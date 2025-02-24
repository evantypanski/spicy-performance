# Spicy Performance Stuff

Analyzing the performance of [Spicy](https://github.com/zeek/spicy) in various contexts.

This is just a set of experiments I have been working on to judge Spicy's performance from a user's perspective. It's not meant to give a super detailed account of how to "fix" any performance issues, it's meant to be transparent about where Spicy may be slow so that users may know.

Every unit is testing a different feature with the same input. It's not exactly perfect, but it will give a sense of how much slower it is to refactor something into a unit vs. use `bytes &until=` vs. a regex, for example.

Here is the output from the initial run I did:

```
           Unit | Sample 1 | Sample 2 | Sample 3 | Sample 4 | Sample 5 | Mean
--------------------------------------------------------------------------------
    BytesLength |    0.006 |    0.006 |    0.005 |    0.006 |    0.005 | 0.006
     BytesUntil |    0.281 |    0.289 |    0.287 |    0.281 |    0.281 | 0.284
          Regex |   10.137 |   10.096 |   10.119 |   10.344 |   10.139 | 10.167
           Sync |    2.333 |    2.326 |    2.331 |    2.327 |    2.327 | 2.329
      SyncRegex |    9.265 |    8.969 |    9.057 |    9.932 |   10.038 | 9.452
          While |    2.758 |    2.709 |    2.711 |    2.744 |    2.727 | 2.730
       WithUnit |   14.351 |   13.673 |   14.070 |   13.736 |   13.907 | 13.947
 WithUnitSwitch |   16.796 |   16.763 |   17.061 |   16.837 |   16.738 | 16.839


Results in order:
    BytesLength: 0.006
     BytesUntil: 0.284
           Sync: 2.329
          While: 2.730
      SyncRegex: 9.452
          Regex: 10.167
       WithUnit: 13.947
 WithUnitSwitch: 16.839
```

## Binpac

Binpac has one dependency on Zeek for regexes. For these tests, I just removed that from the runtime - the rest of it seems to work fine.

```
           Unit | Sample 1 | Sample 2 | Sample 3 | Sample 4 | Sample 5 | Mean
--------------------------------------------------------------------------------
    BytesLength |    1.572 |    1.568 |    1.567 |    1.550 |    1.574 | 1.566
     BytesUntil |    1.606 |    1.592 |    1.637 |    1.640 |    1.642 | 1.623
     WithRecord |    3.815 |    3.648 |    3.665 |    3.805 |    3.741 | 3.735
 WithRecordCase |    4.154 |    4.137 |    4.145 |    4.129 |    4.139 | 4.141


Results in order:
    BytesLength: 1.566
     BytesUntil: 1.623
     WithRecord: 3.735
 WithRecordCase: 4.141
```

For bytes, `bytestring` is a lot more efficient than `uint8` - indeed, swapping the `&until` for `&length` in `BytesUntil` gets pretty similar results, but then swapping to `bytestring` is low overhead. Though, it is roughly the same as Spicy at that point - I would claim that Spicy is "better" there because you can use `&until` with the more efficient type.

The big difference here is that the gap between `BytesLength` and the equivalent `WithUnit` is a lot larger in Spicy. That seems to be the biggest difference between the two, unless regex as well has a large difference. This would make sense - parsers almost always split data among many units, but it turns out that is expensive. Binpac isn't itself fast, but it's faster than Spicy's equivalent.
