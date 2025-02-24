# Spicy Performance Stuff

Analyzing the performance of [Spicy](https://github.com/zeek/spicy) in various contexts.

This is just a set of experiments I have been working on to judge Spicy's performance from a user's perspective. It's not meant to give a super detailed account of how to "fix" any performance issues, it's meant to be transparent about where Spicy may be slow so that users may know.

Every unit is testing a different feature with the same input. It's not exactly perfect, but it will give a sense of how much slower it is to refactor something into a unit vs. use `bytes &until=` vs. a regex, for example.

Here is the output from the initial run I did:

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
