# Spicy Performance Stuff

Analyzing the performance of [Spicy](https://github.com/zeek/spicy) in various contexts.

This is just a set of experiments I have been working on to judge Spicy's performance from a user's perspective. It's not meant to give a super detailed account of how to "fix" any performance issues, it's meant to be transparent about where Spicy may be slow so that users may know.

# Results

The main results are:

1) Spicy patterns are 27x slower than binpac over 100MB of A's - depending on the protocol, this may get very expensive. Spicy units are also about 3-4x slower than binpac records. These both are very common patterns, so this could account for a significant parsing speed difference.
2) Synchronization is "fairly slow" - but not necessarily worrisome. This seems expected and fine.

That's about it. For parsing speed, the lowest hanging fruit by a longshot are regular expressions: they are commonly used and far slower than binpac. But, the utility here might be overstated, as many parsers may not use patterns for large amounts of data.

Unit overhead is significant, but this can possibly be fixed in other ways. For example, there can be a language feature which is simply "plain old data" to allow users to group logical units together without overhead for hooks and whatnot. This can also be done by an optimizer.

There are other minor points: switches in Spicy are relatively slow, and some parsers (like from what I can tell the SSL spicy parser) spend significant time on switch logic. I don't have any ideas for speedup here, but it may be worth noticing :)

This only looked at parsing speed between Spicy and binpac. There are two other points which may be worthwhile to look at: Spicy->Zeek value conversion overhead and fiber overhead. I have nothing to say about those based on this.

# Spicy

Every unit is testing a different feature with the same input. It's not exactly perfect, but it will give a sense of how much slower it is to refactor something into a unit vs. use `bytes &until=` vs. a regex, for example.

Here is the output on my computer:

```
           Unit | Sample 1 | Sample 2 | Sample 3 | Sample 4 | Sample 5 | Mean
--------------------------------------------------------------------------------
    BytesLength |    0.005 |    0.005 |    0.005 |    0.005 |    0.005 | 0.005
     BytesUntil |    0.286 |    0.285 |    0.285 |    0.286 |    0.287 | 0.286
          Regex |   10.284 |   10.220 |   10.218 |   10.233 |   10.187 | 10.228
      SinkUntil |    0.305 |    0.301 |    0.299 |    0.297 |    0.299 | 0.300
           Sync |    2.319 |    2.353 |    2.320 |    2.320 |    2.325 | 2.327
      SyncRegex |    8.783 |    8.773 |    8.753 |    8.997 |    9.123 | 8.886
          While |    2.748 |    2.752 |    2.775 |    2.761 |    2.752 | 2.757
       WithUnit |   14.045 |   14.137 |   14.035 |   14.124 |   14.095 | 14.087
 WithUnitSwitch |   17.483 |   17.202 |   17.367 |   17.017 |   17.090 | 17.232


Results in order:
    BytesLength: 0.005
     BytesUntil: 0.286
      SinkUntil: 0.300
           Sync: 2.327
          While: 2.757
      SyncRegex: 8.886
          Regex: 10.228
       WithUnit: 14.087
 WithUnitSwitch: 17.232
```

> [!NOTE]
> There is a separate `RegexCharacterClass` which only shows a considerable difference when the input is with `Z`'s. The mean for that one with `Z` in my run is 13.514 seconds - so 32% slower than `A*` (or, equivalently, `Z*` when it's all `Z`'s).

## Binpac

Binpac has one dependency on Zeek for regexes. For these tests, I just removed that from the runtime - the rest of it seems to work fine.

```
           Unit | Sample 1 | Sample 2 | Sample 3 | Sample 4 | Sample 5 | Mean
--------------------------------------------------------------------------------
    BytesLength |    0.006 |    0.005 |    0.005 |    0.005 |    0.006 | 0.005
     BytesUntil |    1.640 |    1.640 |    1.649 |    1.623 |    1.621 | 1.635
     WithRecord |    3.882 |    3.808 |    3.802 |    3.771 |    3.779 | 3.809
 WithRecordCase |    4.104 |    4.104 |    4.159 |    4.138 |    4.136 | 4.128


Results in order:
    BytesLength: 0.005
     BytesUntil: 1.635
     WithRecord: 3.809
 WithRecordCase: 4.128
```

For bytes, `bytestring` is a lot more efficient than `uint8` - indeed, swapping the `&until` for `&length` in `BytesUntil` gets pretty similar results, but then swapping to `bytestring` is low overhead. Though, it is roughly the same as Spicy at that point - I would claim that Spicy is "better" there because you can use `&until` with the more efficient type.

The big difference here is that the gap between `BytesLength` and the equivalent `WithUnit` is a lot larger in Spicy. That seems to be the biggest difference between the two, unless regex as well has a large difference. This would make sense - parsers almost always split data among many units, but it turns out that is expensive. Binpac isn't itself fast, but it's faster than Spicy's equivalent.

### Binpac patterns

Regular expressions in binpac are done via Zeek's regex patterns. In order to get this to work, I made a plugin which runs just the regex benchmark. The results look like this regardless of pattern:

```
           Unit | Sample 1 | Sample 2 | Sample 3 | Sample 4 | Sample 5 | Mean
--------------------------------------------------------------------------------
          Regex |    0.376 |    0.381 |    0.380 |    0.380 |    0.370 | 0.378


Results in order:
          Regex: 0.378
```

In order to get this to work, I had to add a `Compile` call to the matcher in binpac's regex header:

```
diff --git a/lib/binpac_regex.h b/lib/binpac_regex.h
index d8e2a05..24fa852 100644
--- a/lib/binpac_regex.h
+++ b/lib/binpac_regex.h
@@ -28,6 +28,7 @@ public:
             uncompiled_re_matchers = new std::vector<zeek::RE_Matcher*>;
 
         re_matcher_ = new zeek::RE_Matcher(pattern_.c_str());
+        re_matcher_->Compile();
         uncompiled_re_matchers->push_back(re_matcher_);
     }
 
```

Maybe I'm doing something wrong, but it wouldn't compile the pattern without that.
