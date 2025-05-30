// Begin of Benchmark (from "../custom.spicy")
// Compiled by HILTI version 1.13.0-dev.128

#include <hilti/rt/compiler-setup.h>
#include <hilti/rt/libhilti.h>

#include <spicy/rt/libspicy.h>

extern const char* __hlt_bench_hlto_scope;

namespace __hlt_bench::Benchmark {
struct Inner;
struct WithUnit;
struct Inner : ::hilti::rt::trait::isStruct, ::hilti::rt::Controllable<Inner> {
    auto __self() { return ::hilti::rt::ValueReference<Inner>::self(this); }
    std::optional<::hilti::rt::integer::safe<uint8_t>> b{};
    auto __parse_stage1(::hilti::rt::ValueReference<::hilti::rt::Stream>& __data,
                        const ::hilti::rt::stream::SafeConstIterator& __begin, ::hilti::rt::stream::View __cur,
                        ::hilti::rt::Bool __trim, ::hilti::rt::integer::safe<int64_t> __lah,
                        ::hilti::rt::stream::SafeConstIterator __lahe,
                        std::optional<::hilti::rt::RecoverableFailure> __error)
        -> std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>,
                      ::hilti::rt::stream::SafeConstIterator, std::optional<::hilti::rt::RecoverableFailure>>;
    auto __parse_Benchmark__Inner_stage2(::hilti::rt::ValueReference<::hilti::rt::Stream>& __data,
                                         const ::hilti::rt::stream::SafeConstIterator& __begin,
                                         ::hilti::rt::stream::View __cur, ::hilti::rt::Bool __trim,
                                         ::hilti::rt::integer::safe<int64_t> __lah,
                                         ::hilti::rt::stream::SafeConstIterator __lahe,
                                         std::optional<::hilti::rt::RecoverableFailure> __error)
        -> std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>,
                      ::hilti::rt::stream::SafeConstIterator, std::optional<::hilti::rt::RecoverableFailure>>;
    std::optional<::hilti::rt::RecoverableFailure> __error{};
    Inner();
    Inner(const Inner&) = default;
    Inner(Inner&&) = default;
    Inner& operator=(const Inner&) = default;
    Inner& operator=(Inner&&) = default;
    Inner(std::optional<std::optional<::hilti::rt::integer::safe<uint8_t>>> b);
    template<typename F>
    void __visit(F _) const {
        _("b", b);
    }

    std::string __to_string() const { return "["s + "$b=" + hilti::rt::to_string(b) + "]"; }
};

struct WithUnit : ::hilti::rt::trait::isStruct, ::hilti::rt::Controllable<WithUnit> {
    auto __self() { return ::hilti::rt::ValueReference<WithUnit>::self(this); }
    std::optional<::hilti::rt::integer::safe<uint64_t>> length{};
    std::optional<::hilti::rt::Vector<Inner>> inner{};
    std::optional<::hilti::rt::Bytes> end_{};
    inline static ::spicy::rt::Parser __parser{};
    auto __parse_stage1(::hilti::rt::ValueReference<::hilti::rt::Stream>& __data,
                        const ::hilti::rt::stream::SafeConstIterator& __begin, ::hilti::rt::stream::View __cur,
                        ::hilti::rt::Bool __trim, ::hilti::rt::integer::safe<int64_t> __lah,
                        ::hilti::rt::stream::SafeConstIterator __lahe,
                        std::optional<::hilti::rt::RecoverableFailure> __error)
        -> std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>,
                      ::hilti::rt::stream::SafeConstIterator, std::optional<::hilti::rt::RecoverableFailure>>;
    static auto parse1(::hilti::rt::ValueReference<::hilti::rt::Stream>& __data,
                       const std::optional<::hilti::rt::stream::View>& __cur,
                       const std::optional<::spicy::rt::UnitContext>& __context) -> ::hilti::rt::stream::View;
    static auto parse2(::hilti::rt::ValueReference<WithUnit>& __unit,
                       ::hilti::rt::ValueReference<::hilti::rt::Stream>& __data,
                       const std::optional<::hilti::rt::stream::View>& __cur,
                       const std::optional<::spicy::rt::UnitContext>& __context) -> ::hilti::rt::stream::View;
    static auto parse3(::hilti::rt::ValueReference<::spicy::rt::ParsedUnit>& __gunit,
                       ::hilti::rt::ValueReference<::hilti::rt::Stream>& __data,
                       const std::optional<::hilti::rt::stream::View>& __cur,
                       const std::optional<::spicy::rt::UnitContext>& __context) -> ::hilti::rt::stream::View;
    auto __parse_inner_stage1(::hilti::rt::ValueReference<::hilti::rt::Stream>& __data,
                              const ::hilti::rt::stream::SafeConstIterator& __begin, ::hilti::rt::stream::View __cur,
                              ::hilti::rt::Bool __trim, ::hilti::rt::integer::safe<int64_t> __lah,
                              ::hilti::rt::stream::SafeConstIterator __lahe,
                              std::optional<::hilti::rt::RecoverableFailure> __error, ::hilti::rt::Vector<Inner>& __dst)
        -> std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>,
                      ::hilti::rt::stream::SafeConstIterator, std::optional<::hilti::rt::RecoverableFailure>>;
    auto __parse_Benchmark__WithUnit_stage2(::hilti::rt::ValueReference<::hilti::rt::Stream>& __data,
                                            const ::hilti::rt::stream::SafeConstIterator& __begin,
                                            ::hilti::rt::stream::View __cur, ::hilti::rt::Bool __trim,
                                            ::hilti::rt::integer::safe<int64_t> __lah,
                                            ::hilti::rt::stream::SafeConstIterator __lahe,
                                            std::optional<::hilti::rt::RecoverableFailure> __error)
        -> std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>,
                      ::hilti::rt::stream::SafeConstIterator, std::optional<::hilti::rt::RecoverableFailure>>;
    std::optional<::hilti::rt::RecoverableFailure> __error{};
    WithUnit();
    WithUnit(const WithUnit&) = default;
    WithUnit(WithUnit&&) = default;
    WithUnit& operator=(const WithUnit&) = default;
    WithUnit& operator=(WithUnit&&) = default;
    WithUnit(std::optional<std::optional<::hilti::rt::integer::safe<uint64_t>>> length,
             std::optional<std::optional<::hilti::rt::Vector<Inner>>> inner,
             std::optional<std::optional<::hilti::rt::Bytes>> end_);
    template<typename F>
    void __visit(F _) const {
        _("length", length);
        _("inner", inner);
        _("end_", end_);
    }

    std::string __to_string() const {
        return "["s + "$length=" + hilti::rt::to_string(length) +
               ", "
               "$inner=" +
               hilti::rt::to_string(inner) +
               ", "
               "$end_=" +
               hilti::rt::to_string(end_) + "]";
    }
};

const ::hilti::rt::Bytes __ctor__bytes = "BB"_b;
const ::hilti::rt::Bool __feat0x25Benchmark0x400x40Inner0x25is_filter = ::hilti::rt::Bool(false);
const ::hilti::rt::Bool __feat0x25Benchmark0x400x40Inner0x25supports_filters = ::hilti::rt::Bool(false);
const ::hilti::rt::Bool __feat0x25Benchmark0x400x40Inner0x25supports_sinks = ::hilti::rt::Bool(false);
const ::hilti::rt::Bool __feat0x25Benchmark0x400x40Inner0x25synchronization = ::hilti::rt::Bool(false);
const ::hilti::rt::Bool __feat0x25Benchmark0x400x40Inner0x25uses_offset = ::hilti::rt::Bool(false);
const ::hilti::rt::Bool __feat0x25Benchmark0x400x40Inner0x25uses_random_access = ::hilti::rt::Bool(false);
const ::hilti::rt::Bool __feat0x25Benchmark0x400x40Inner0x25uses_stream = ::hilti::rt::Bool(false);
const ::hilti::rt::Bool __feat0x25Benchmark0x400x40Inner0x25uses_sync_advance = ::hilti::rt::Bool(false);
const ::hilti::rt::Bool __feat0x25Benchmark0x400x40WithUnit0x25is_filter = ::hilti::rt::Bool(false);
const ::hilti::rt::Bool __feat0x25Benchmark0x400x40WithUnit0x25supports_filters = ::hilti::rt::Bool(false);
const ::hilti::rt::Bool __feat0x25Benchmark0x400x40WithUnit0x25supports_sinks = ::hilti::rt::Bool(false);
const ::hilti::rt::Bool __feat0x25Benchmark0x400x40WithUnit0x25synchronization = ::hilti::rt::Bool(false);
const ::hilti::rt::Bool __feat0x25Benchmark0x400x40WithUnit0x25uses_offset = ::hilti::rt::Bool(false);
const ::hilti::rt::Bool __feat0x25Benchmark0x400x40WithUnit0x25uses_random_access = ::hilti::rt::Bool(false);
const ::hilti::rt::Bool __feat0x25Benchmark0x400x40WithUnit0x25uses_stream = ::hilti::rt::Bool(false);
const ::hilti::rt::Bool __feat0x25Benchmark0x400x40WithUnit0x25uses_sync_advance = ::hilti::rt::Bool(false);
} // namespace __hlt_bench::Benchmark

namespace hlt_bench::Benchmark::WithUnit {
using Type = __hlt_bench::Benchmark::WithUnit;
}

namespace __hlt_bench::Benchmark {
extern auto operator<<(std::ostream& o, const __hlt_bench::Benchmark::Inner& x) -> std::ostream&;
Inner::Inner() {}

Inner::Inner(std::optional<std::optional<::hilti::rt::integer::safe<uint8_t>>> b) : Inner() {
    if ( b )
        this->b = std::move(*b);
}


extern auto operator<<(std::ostream& o, const __hlt_bench::Benchmark::WithUnit& x) -> std::ostream&;
WithUnit::WithUnit() {}

WithUnit::WithUnit(std::optional<std::optional<::hilti::rt::integer::safe<uint64_t>>> length,
                   std::optional<std::optional<::hilti::rt::Vector<__hlt_bench::Benchmark::Inner>>> inner,
                   std::optional<std::optional<::hilti::rt::Bytes>> end_)
    : WithUnit() {
    if ( length )
        this->length = std::move(*length);
    if ( inner )
        this->inner = std::move(*inner);
    if ( end_ )
        this->end_ = std::move(*end_);
}


} // namespace __hlt_bench::Benchmark

namespace hlt_bench::Benchmark::WithUnit {
extern auto parse1(::hilti::rt::ValueReference<::hilti::rt::Stream>& __data,
                   const std::optional<::hilti::rt::stream::View>& __cur,
                   const std::optional<::spicy::rt::UnitContext>& __context) -> ::hilti::rt::Resumable;
extern auto parse2(::hilti::rt::ValueReference<__hlt_bench::Benchmark::WithUnit>& __unit,
                   ::hilti::rt::ValueReference<::hilti::rt::Stream>& __data,
                   const std::optional<::hilti::rt::stream::View>& __cur,
                   const std::optional<::spicy::rt::UnitContext>& __context) -> ::hilti::rt::Resumable;
extern auto parse3(::hilti::rt::ValueReference<::spicy::rt::ParsedUnit>& __gunit,
                   ::hilti::rt::ValueReference<::hilti::rt::Stream>& __data,
                   const std::optional<::hilti::rt::stream::View>& __cur,
                   const std::optional<::spicy::rt::UnitContext>& __context) -> ::hilti::rt::Resumable;
} // namespace hlt_bench::Benchmark::WithUnit

namespace __hlt_bench::Benchmark {
extern void __register_Benchmark_Inner();
extern void __register_Benchmark_WithUnit();
extern void __init_module();
extern void __register_module();
} // namespace __hlt_bench::Benchmark

namespace __hlt_bench::type_info {
namespace {
extern const ::hilti::rt::TypeInfo __ti_Benchmark__Inner_namex2aBenchmark__Innerx2b;
extern const ::hilti::rt::TypeInfo
    __ti_optional_spicy__RecoverableFailure__optionalx2anamex2ahilti__RecoverableFailurex2bx2b;
extern const ::hilti::rt::TypeInfo __ti_hilti__RecoverableFailure_namex2ahilti__RecoverableFailurex2b;
const ::hilti::rt::TypeInfo __ti_hilti__RecoverableFailure_namex2ahilti__RecoverableFailurex2b =
    {"hilti::RecoverableFailure", "hilti::RecoverableFailure",
     [](const void* self) {
         return hilti::rt::to_string(*reinterpret_cast<const ::hilti::rt::RecoverableFailure*>(self));
     },
     new ::hilti::rt::type_info::Exception()};
const ::hilti::rt::TypeInfo __ti_optional_spicy__RecoverableFailure__optionalx2anamex2ahilti__RecoverableFailurex2bx2b =
    {{},
     "optional<spicy::RecoverableFailure>",
     [](const void* self) {
         return hilti::rt::to_string(*reinterpret_cast<const std::optional<::hilti::rt::RecoverableFailure>*>(self));
     },
     new ::hilti::rt::type_info::
         Optional(&type_info::__ti_hilti__RecoverableFailure_namex2ahilti__RecoverableFailurex2b,
                  ::hilti::rt::type_info::Optional::accessor<::hilti::rt::RecoverableFailure>())};
const ::hilti::rt::TypeInfo __ti_Benchmark__Inner_namex2aBenchmark__Innerx2b =
    {"Benchmark::Inner", "Benchmark::Inner",
     [](const void* self) {
         return hilti::rt::to_string(*reinterpret_cast<const __hlt_bench::Benchmark::Inner*>(self));
     },
     new ::hilti::rt::type_info::Struct(std::vector<::hilti::rt::type_info::struct_::Field>(
         {::hilti::rt::type_info::struct_::Field{"b", &::hilti::rt::type_info::uint8, offsetof(Benchmark::Inner, b),
                                                 false, false,
                                                 ::hilti::rt::type_info::struct_::Field::accessor_optional<
                                                     ::hilti::rt::integer::safe<uint8_t>>()},
          ::hilti::rt::type_info::struct_::Field{
              "__error",
              &type_info::__ti_optional_spicy__RecoverableFailure__optionalx2anamex2ahilti__RecoverableFailurex2bx2b,
              offsetof(Benchmark::Inner, __error), true, false}}))};
extern const ::hilti::rt::TypeInfo __ti_Benchmark__WithUnit_namex2aBenchmark__WithUnitx2b;
extern const ::hilti::rt::TypeInfo __ti_vector_Inner__vectorx2anamex2aBenchmark__Innerx2bx2b;
const ::hilti::rt::TypeInfo __ti_vector_Inner__vectorx2anamex2aBenchmark__Innerx2bx2b =
    {{},
     "vector<Inner>",
     [](const void* self) {
         return hilti::rt::to_string(
             *reinterpret_cast<const ::hilti::rt::Vector<__hlt_bench::Benchmark::Inner>*>(self));
     },
     new ::hilti::rt::type_info::Vector(&type_info::__ti_Benchmark__Inner_namex2aBenchmark__Innerx2b,
                                        ::hilti::rt::type_info::Vector::accessor<__hlt_bench::Benchmark::Inner>())};
const ::hilti::rt::TypeInfo __ti_Benchmark__WithUnit_namex2aBenchmark__WithUnitx2b =
    {"Benchmark::WithUnit", "Benchmark::WithUnit",
     [](const void* self) {
         return hilti::rt::to_string(*reinterpret_cast<const __hlt_bench::Benchmark::WithUnit*>(self));
     },
     new ::hilti::rt::type_info::Struct(std::vector<::hilti::rt::type_info::struct_::Field>(
         {::hilti::rt::type_info::struct_::Field{"length", &::hilti::rt::type_info::uint64,
                                                 offsetof(Benchmark::WithUnit, length), false, false,
                                                 ::hilti::rt::type_info::struct_::Field::accessor_optional<
                                                     ::hilti::rt::integer::safe<uint64_t>>()},
          ::hilti::rt::type_info::struct_::Field{"inner",
                                                 &type_info::__ti_vector_Inner__vectorx2anamex2aBenchmark__Innerx2bx2b,
                                                 offsetof(Benchmark::WithUnit, inner), false, false,
                                                 ::hilti::rt::type_info::struct_::Field::accessor_optional<
                                                     ::hilti::rt::Vector<__hlt_bench::Benchmark::Inner>>()},
          ::hilti::rt::type_info::struct_::Field{"end_", &::hilti::rt::type_info::bytes,
                                                 offsetof(Benchmark::WithUnit, end_), false, false,
                                                 ::hilti::rt::type_info::struct_::Field::accessor_optional<
                                                     ::hilti::rt::Bytes>()},
          ::hilti::rt::type_info::struct_::Field{
              "__error",
              &type_info::__ti_optional_spicy__RecoverableFailure__optionalx2anamex2ahilti__RecoverableFailurex2bx2b,
              offsetof(Benchmark::WithUnit, __error), true, false}}))};
} // namespace
} // namespace __hlt_bench::type_info

HILTI_PRE_INIT(__hlt_bench::Benchmark::__register_module)

auto __hlt_bench::Benchmark::Inner::__parse_Benchmark__Inner_stage2(
    ::hilti::rt::ValueReference<::hilti::rt::Stream>& __data, const ::hilti::rt::stream::SafeConstIterator& __begin,
    ::hilti::rt::stream::View __cur, ::hilti::rt::Bool __trim, ::hilti::rt::integer::safe<int64_t> __lah,
    ::hilti::rt::stream::SafeConstIterator __lahe, std::optional<::hilti::rt::RecoverableFailure> __error)
    -> std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>,
                  ::hilti::rt::stream::SafeConstIterator, std::optional<::hilti::rt::RecoverableFailure>> {
    auto __self = Inner::__self();
    ::hilti::rt::detail::checkStack();
    __location__("../custom.spicy:3:14-5:1");
    std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>, ::hilti::rt::stream::SafeConstIterator,
               std::optional<::hilti::rt::RecoverableFailure>>
        __result;

    {
        __location__("../custom.spicy:4:8-4:12");

        // Begin parsing production: Variable: b   -> uint<8>;
        ::spicy::rt::detail::waitForInput(__data, __cur, ::hilti::rt::integer::safe<std::uint64_t>{1U},
                                          "expecting 1 bytes for unpacking value"sv, "../custom.spicy:4:8-4:12"sv,
                                          ::hilti::rt::StrongReference<::spicy::rt::filter::detail::Filters>());
        std::tie(::hilti::rt::optional::valueOrInit((*__self).b), __cur) =
            ::hilti::rt::integer::unpack<uint8_t>(__cur, ::hilti::rt::ByteOrder{::hilti::rt::ByteOrder::Network})
                .valueOrThrow();
        if ( __trim ) {
            (*__data).trim(__cur.begin());
        }

        // End parsing production: Variable: b   -> uint<8>;
    }

    ::hilti::rt::debug::dedent("spicy"sv);
    __result = std::make_tuple(__cur, __lah, __lahe, __error);
    return __result;
}

auto __hlt_bench::Benchmark::Inner::__parse_stage1(::hilti::rt::ValueReference<::hilti::rt::Stream>& __data,
                                                   const ::hilti::rt::stream::SafeConstIterator& __begin,
                                                   ::hilti::rt::stream::View __cur, ::hilti::rt::Bool __trim,
                                                   ::hilti::rt::integer::safe<int64_t> __lah,
                                                   ::hilti::rt::stream::SafeConstIterator __lahe,
                                                   std::optional<::hilti::rt::RecoverableFailure> __error)
    -> std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>,
                  ::hilti::rt::stream::SafeConstIterator, std::optional<::hilti::rt::RecoverableFailure>> {
    auto __self = Inner::__self();
    ::hilti::rt::detail::checkStack();
    __location__("../custom.spicy:3:14-5:1");
    std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>, ::hilti::rt::stream::SafeConstIterator,
               std::optional<::hilti::rt::RecoverableFailure>>
        __result;

    {
        ::hilti::rt::debug::indent("spicy"sv);
        ::hilti::rt::stream::SafeConstIterator __begin = __cur.begin();
        ::hilti::rt::StrongReference<::hilti::rt::Stream> filtered =
            ::hilti::rt::StrongReference<::hilti::rt::Stream>();
        if ( ! (::hilti::rt::Bool(static_cast<bool>(filtered))) ) {
            __result =
                (*__self).__parse_Benchmark__Inner_stage2(__data, __begin, __cur, __trim, __lah, __lahe, __error);
        }
    }

    return __result;
}

auto __hlt_bench::Benchmark::WithUnit::__parse_Benchmark__WithUnit_stage2(
    ::hilti::rt::ValueReference<::hilti::rt::Stream>& __data, const ::hilti::rt::stream::SafeConstIterator& __begin,
    ::hilti::rt::stream::View __cur, ::hilti::rt::Bool __trim, ::hilti::rt::integer::safe<int64_t> __lah,
    ::hilti::rt::stream::SafeConstIterator __lahe, std::optional<::hilti::rt::RecoverableFailure> __error)
    -> std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>,
                  ::hilti::rt::stream::SafeConstIterator, std::optional<::hilti::rt::RecoverableFailure>> {
    auto __self = WithUnit::__self();
    ::hilti::rt::detail::checkStack();
    __location__("../custom.spicy:7:24-11:1");
    std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>, ::hilti::rt::stream::SafeConstIterator,
               std::optional<::hilti::rt::RecoverableFailure>>
        __result;

    {
        __location__("../custom.spicy:8:13-8:18");

        // Begin parsing production: Variable: length -> uint<64>;
        ::spicy::rt::detail::waitForInput(__data, __cur, ::hilti::rt::integer::safe<std::uint64_t>{8U},
                                          "expecting 8 bytes for unpacking value"sv, "../custom.spicy:8:13-8:18"sv,
                                          ::hilti::rt::StrongReference<::spicy::rt::filter::detail::Filters>());
        std::tie(::hilti::rt::optional::valueOrInit((*__self).length), __cur) =
            ::hilti::rt::integer::unpack<uint64_t>(__cur, ::hilti::rt::ByteOrder{::hilti::rt::ByteOrder::Network})
                .valueOrThrow();
        if ( __trim ) {
            (*__data).trim(__cur.begin());
        }

        // End parsing production: Variable: length -> uint<64>;
    }

    {
        __location__("../custom.spicy:9:5-9:37");
        ::hilti::rt::integer::safe<uint64_t> __pre_container_offset = ::hilti::rt::integer::safe<std::uint64_t>{0U};

        // Begin parsing production: ForEach: inner -> foreach: Resolved_3;
        ::hilti::rt::stream::View __limited_ = __cur.limit(::hilti::rt::optional::value((*__self).length));
        ::hilti::rt::stream::View __ncur = __cur.advance(::hilti::rt::optional::value((*__self).length));
        std::tie(__limited_, __lah, __lahe, __error) =
            (*__self).__parse_inner_stage1(__data, __begin, __limited_, __trim, __lah, __lahe, __error,
                                           ::hilti::rt::optional::valueOrInit((*__self).inner));
        if ( __limited_.offset() < __ncur.offset() ) {
            (*__self).inner.reset();
            __location__("../custom.spicy:9:20-9:36");
            throw ::spicy::rt::
                ParseError(::hilti::rt::fmt("&size amount not consumed: expected %llu bytes, but got %llu bytes"sv,
                                            ::hilti::rt::optional::value((*__self).length),
                                            __limited_.offset() -
                                                (__ncur.offset() - ::hilti::rt::optional::value((*__self).length))),
                           "../custom.spicy:9:20-9:36");
        }

        // End parsing production: ForEach: inner -> foreach: Resolved_3;

        ::hilti::rt::integer::safe<uint64_t> __prev = ::hilti::rt::integer::safe<std::uint64_t>{0U};
        __cur = __ncur;
    }

    {
        ::hilti::rt::StrongReference<::spicy::rt::filter::detail::Filters> __lhs_1;
        __location__("../custom.spicy:10:11-10:15");

        // Begin parsing production: Ctor: end_ -> b"BB" (const bytes);
        ::spicy::rt::detail::expectBytesLiteral(__data, __cur, __hlt_bench::Benchmark::__ctor__bytes,
                                                "../custom.spicy:10:11-10:15"sv,
                                                (__lhs_1 = (::hilti::rt::StrongReference<
                                                            ::spicy::rt::filter::detail::Filters>())));
        ::hilti::rt::optional::valueOrInit((*__self).end_) = __hlt_bench::Benchmark::__ctor__bytes;
        __cur = __cur.advance(::hilti::rt::integer::safe<std::uint64_t>{2U});
        if ( __trim ) {
            (*__data).trim(__cur.begin());
        }

        // End parsing production: Ctor: end_ -> b"BB" (const bytes);
    }

    ::hilti::rt::debug::dedent("spicy"sv);
    __result = std::make_tuple(__cur, __lah, __lahe, __error);
    return __result;
}

auto __hlt_bench::Benchmark::WithUnit::__parse_inner_stage1(::hilti::rt::ValueReference<::hilti::rt::Stream>& __data,
                                                            const ::hilti::rt::stream::SafeConstIterator& __begin,
                                                            ::hilti::rt::stream::View __cur, ::hilti::rt::Bool __trim,
                                                            ::hilti::rt::integer::safe<int64_t> __lah,
                                                            ::hilti::rt::stream::SafeConstIterator __lahe,
                                                            std::optional<::hilti::rt::RecoverableFailure> __error,
                                                            ::hilti::rt::Vector<__hlt_bench::Benchmark::Inner>& __dst)
    -> std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>,
                  ::hilti::rt::stream::SafeConstIterator, std::optional<::hilti::rt::RecoverableFailure>> {
    ::hilti::rt::StrongReference<::spicy::rt::filter::detail::Filters> __lhs_2;
    auto __self = WithUnit::__self();
    ::hilti::rt::detail::checkStack();
    __location__("../custom.spicy:9:5-9:37");
    std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>, ::hilti::rt::stream::SafeConstIterator,
               std::optional<::hilti::rt::RecoverableFailure>>
        __result;
    while (
        ! (::spicy::rt::detail::atEod(__data, __cur,
                                      (__lhs_2 =
                                           (::hilti::rt::StrongReference<::spicy::rt::filter::detail::Filters>())))) ) {
        ::hilti::rt::StrongReference<::spicy::rt::filter::detail::Filters> __lhs_3;
        ::hilti::rt::stream::SafeConstIterator __old_begin = __cur.begin();
        ::hilti::rt::ValueReference<__hlt_bench::Benchmark::Inner> __elem;
        __location__("../custom.spicy:3:14-5:1");

        // Begin parsing production: Unit: Benchmark__Inner_2 -> b_2 (container 'inner');
        __elem = (__hlt_bench::Benchmark::Inner());
        std::tie(__cur, __lah, __lahe, __error) =
            (*__elem).__parse_stage1(__data, __begin, __cur, __trim, __lah, __lahe, __error);
        // End parsing production: Unit: Benchmark__Inner_2 -> b_2 (container 'inner');

        ::hilti::rt::Bool __stop = ::hilti::rt::Bool(false);
        if ( ! (__stop) ) {
        }

        if ( ! (__stop) ) {
            __dst.emplace_back((*__elem));
        }

        if ( __stop ) {
            break;
        }

        if ( (__cur.begin() == __old_begin) &&
             (! (::spicy::rt::detail::atEod(__data, __cur,
                                            (__lhs_3 = (::hilti::rt::StrongReference<
                                                        ::spicy::rt::filter::detail::Filters>()))))) ) {
            __location__("../custom.spicy:9:5-9:37");
            throw ::spicy::rt::ParseError("loop body did not change input position, possible infinite loop"sv,
                                          "../custom.spicy:9:5-9:37");
        }
    }

    __result = std::make_tuple(__cur, __lah, __lahe, __error);
    return __result;
}

auto __hlt_bench::Benchmark::WithUnit::__parse_stage1(::hilti::rt::ValueReference<::hilti::rt::Stream>& __data,
                                                      const ::hilti::rt::stream::SafeConstIterator& __begin,
                                                      ::hilti::rt::stream::View __cur, ::hilti::rt::Bool __trim,
                                                      ::hilti::rt::integer::safe<int64_t> __lah,
                                                      ::hilti::rt::stream::SafeConstIterator __lahe,
                                                      std::optional<::hilti::rt::RecoverableFailure> __error)
    -> std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>,
                  ::hilti::rt::stream::SafeConstIterator, std::optional<::hilti::rt::RecoverableFailure>> {
    auto __self = WithUnit::__self();
    ::hilti::rt::detail::checkStack();
    __location__("../custom.spicy:7:24-11:1");
    std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>, ::hilti::rt::stream::SafeConstIterator,
               std::optional<::hilti::rt::RecoverableFailure>>
        __result;

    {
        ::hilti::rt::debug::indent("spicy"sv);
        ::hilti::rt::stream::SafeConstIterator __begin = __cur.begin();
        ::hilti::rt::StrongReference<::hilti::rt::Stream> filtered =
            ::hilti::rt::StrongReference<::hilti::rt::Stream>();
        if ( ! (::hilti::rt::Bool(static_cast<bool>(filtered))) ) {
            __result =
                (*__self).__parse_Benchmark__WithUnit_stage2(__data, __begin, __cur, __trim, __lah, __lahe, __error);
        }
    }

    return __result;
}

extern auto __hlt_bench::Benchmark::WithUnit::parse1(::hilti::rt::ValueReference<::hilti::rt::Stream>& __data,
                                                     const std::optional<::hilti::rt::stream::View>& __cur,
                                                     const std::optional<::spicy::rt::UnitContext>& __context)
    -> ::hilti::rt::stream::View {
    ::hilti::rt::detail::checkStack();
    __location__("../custom.spicy:7:24-11:1");
    ::hilti::rt::ValueReference<__hlt_bench::Benchmark::WithUnit> __unit =
        ::hilti::rt::reference::make_value<__hlt_bench::Benchmark::WithUnit>((__hlt_bench::Benchmark::WithUnit()));
    ::hilti::rt::stream::View __ncur = (__cur ? ::hilti::rt::optional::value(__cur) : (*__data).view());
    ::hilti::rt::integer::safe<int64_t> __lahead = ::hilti::rt::integer::safe<std::int64_t>{0};
    ::hilti::rt::stream::SafeConstIterator __lahead_end;
    std::optional<::hilti::rt::RecoverableFailure> __error = std::optional<::hilti::rt::RecoverableFailure>();
    __location__("../custom.spicy:7:24-11:1");

    // Begin parsing production: Unit: Benchmark__WithUnit -> length inner end_;
    std::tie(__ncur, __lahead, __lahead_end, __error) =
        (*__unit).__parse_stage1(__data, __ncur.begin(), __ncur, ::hilti::rt::Bool(true), __lahead, __lahead_end,
                                 __error);
    // End parsing production: Unit: Benchmark__WithUnit -> length inner end_;

    if ( __error.has_value() ) {
        throw ::spicy::rt::ParseError(::hilti::rt::fmt("successful synchronization never confirmed: %s"sv,
                                                       ::hilti::rt::exception::what(
                                                           ::hilti::rt::optional::value(__error))),
                                      ::hilti::rt::exception::where(::hilti::rt::optional::value(__error)));
    }

    return __ncur;
}

extern auto __hlt_bench::Benchmark::WithUnit::parse2(
    ::hilti::rt::ValueReference<__hlt_bench::Benchmark::WithUnit>& __unit,
    ::hilti::rt::ValueReference<::hilti::rt::Stream>& __data, const std::optional<::hilti::rt::stream::View>& __cur,
    const std::optional<::spicy::rt::UnitContext>& __context) -> ::hilti::rt::stream::View {
    ::hilti::rt::detail::checkStack();
    __location__("../custom.spicy:7:24-11:1");
    ::hilti::rt::stream::View __ncur = (__cur ? ::hilti::rt::optional::value(__cur) : (*__data).view());
    ::hilti::rt::integer::safe<int64_t> __lahead = ::hilti::rt::integer::safe<std::int64_t>{0};
    ::hilti::rt::stream::SafeConstIterator __lahead_end;
    std::optional<::hilti::rt::RecoverableFailure> __error = std::optional<::hilti::rt::RecoverableFailure>();
    __location__("../custom.spicy:7:24-11:1");

    // Begin parsing production: Unit: Benchmark__WithUnit -> length inner end_;
    std::tie(__ncur, __lahead, __lahead_end, __error) =
        (*__unit).__parse_stage1(__data, __ncur.begin(), __ncur, ::hilti::rt::Bool(true), __lahead, __lahead_end,
                                 __error);
    // End parsing production: Unit: Benchmark__WithUnit -> length inner end_;

    if ( __error.has_value() ) {
        throw ::spicy::rt::ParseError(::hilti::rt::fmt("successful synchronization never confirmed: %s"sv,
                                                       ::hilti::rt::exception::what(
                                                           ::hilti::rt::optional::value(__error))),
                                      ::hilti::rt::exception::where(::hilti::rt::optional::value(__error)));
    }

    return __ncur;
}

extern auto __hlt_bench::Benchmark::WithUnit::parse3(::hilti::rt::ValueReference<::spicy::rt::ParsedUnit>& __gunit,
                                                     ::hilti::rt::ValueReference<::hilti::rt::Stream>& __data,
                                                     const std::optional<::hilti::rt::stream::View>& __cur,
                                                     const std::optional<::spicy::rt::UnitContext>& __context)
    -> ::hilti::rt::stream::View {
    ::hilti::rt::detail::checkStack();
    __location__("../custom.spicy:7:24-11:1");
    ::hilti::rt::ValueReference<__hlt_bench::Benchmark::WithUnit> __unit =
        ::hilti::rt::reference::make_value<__hlt_bench::Benchmark::WithUnit>((__hlt_bench::Benchmark::WithUnit()));
    ::spicy::rt::ParsedUnit::initialize((*__gunit), __unit,
                                        &type_info::__ti_Benchmark__WithUnit_namex2aBenchmark__WithUnitx2b);
    ::hilti::rt::stream::View __ncur = (__cur ? ::hilti::rt::optional::value(__cur) : (*__data).view());
    ::hilti::rt::integer::safe<int64_t> __lahead = ::hilti::rt::integer::safe<std::int64_t>{0};
    ::hilti::rt::stream::SafeConstIterator __lahead_end;
    std::optional<::hilti::rt::RecoverableFailure> __error = std::optional<::hilti::rt::RecoverableFailure>();
    __location__("../custom.spicy:7:24-11:1");

    // Begin parsing production: Unit: Benchmark__WithUnit -> length inner end_;
    std::tie(__ncur, __lahead, __lahead_end, __error) =
        (*__unit).__parse_stage1(__data, __ncur.begin(), __ncur, ::hilti::rt::Bool(true), __lahead, __lahead_end,
                                 __error);
    // End parsing production: Unit: Benchmark__WithUnit -> length inner end_;

    if ( __error.has_value() ) {
        throw ::spicy::rt::ParseError(::hilti::rt::fmt("successful synchronization never confirmed: %s"sv,
                                                       ::hilti::rt::exception::what(
                                                           ::hilti::rt::optional::value(__error))),
                                      ::hilti::rt::exception::where(::hilti::rt::optional::value(__error)));
    }

    return __ncur;
}

extern void __hlt_bench::Benchmark::__init_module() {
    __hlt_bench::Benchmark::__register_Benchmark_Inner();
    __hlt_bench::Benchmark::__register_Benchmark_WithUnit();
}

extern void __hlt_bench::Benchmark::__register_Benchmark_Inner() { ::hilti::rt::detail::checkStack(); }

extern void __hlt_bench::Benchmark::__register_Benchmark_WithUnit() {
    ::hilti::rt::detail::checkStack();
    Benchmark::WithUnit::__parser =
        ::spicy::rt::Parser("Benchmark::WithUnit"sv, ::hilti::rt::Bool(true), hlt_bench::Benchmark::WithUnit::parse1,
                            hlt_bench::Benchmark::WithUnit::parse2, hlt_bench::Benchmark::WithUnit::parse3,
                            ::hilti::rt::Null(), &type_info::__ti_Benchmark__WithUnit_namex2aBenchmark__WithUnitx2b,
                            ""s, ::hilti::rt::Vector<::spicy::rt::MIMEType>({}),
                            ::hilti::rt::Vector<::spicy::rt::ParserPort>({}));
    ::spicy::rt::detail::registerParser(Benchmark::WithUnit::__parser, std::string(__hlt_bench_hlto_scope),
                                        ::hilti::rt::StrongReference<__hlt_bench::Benchmark::WithUnit>());
}

extern void __hlt_bench::Benchmark::__register_module() {
    ::hilti::rt::detail::registerModule(
        {"Benchmark", __hlt_bench_hlto_scope, &__init_module, nullptr, nullptr, nullptr});
}

extern auto __hlt_bench::Benchmark::operator<<(std::ostream& o, const __hlt_bench::Benchmark::Inner& x)
    -> std::ostream& {
    return o << ::hilti::rt::to_string(x);
    ;
}

extern auto __hlt_bench::Benchmark::operator<<(std::ostream& o, const __hlt_bench::Benchmark::WithUnit& x)
    -> std::ostream& {
    return o << ::hilti::rt::to_string(x);
    ;
}

extern auto hlt_bench::Benchmark::WithUnit::parse1(::hilti::rt::ValueReference<::hilti::rt::Stream>& __data,
                                                   const std::optional<::hilti::rt::stream::View>& __cur,
                                                   const std::optional<::spicy::rt::UnitContext>& __context)
    -> ::hilti::rt::Resumable {
    auto args =
        std::make_tuple(::hilti::rt::resumable::detail::copyArg(__data), ::hilti::rt::resumable::detail::copyArg(__cur),
                        ::hilti::rt::resumable::detail::copyArg(__context));
    auto args_on_heap = std::make_shared<decltype(args)>(std::move(args));
    auto cb = [args_on_heap = std::move(args_on_heap)](::hilti::rt::resumable::Handle* r) -> ::hilti::rt::any {
        return __hlt_bench::Benchmark::WithUnit::parse1(std::get<0>(*args_on_heap), std::get<1>(*args_on_heap),
                                                        std::get<2>(*args_on_heap));
    };

    auto r = std::make_unique<::hilti::rt::Resumable>(std::move(cb));
    r->run();
    return std::move(*r);
}

extern auto hlt_bench::Benchmark::WithUnit::parse2(
    ::hilti::rt::ValueReference<__hlt_bench::Benchmark::WithUnit>& __unit,
    ::hilti::rt::ValueReference<::hilti::rt::Stream>& __data, const std::optional<::hilti::rt::stream::View>& __cur,
    const std::optional<::spicy::rt::UnitContext>& __context) -> ::hilti::rt::Resumable {
    auto args =
        std::make_tuple(::hilti::rt::resumable::detail::copyArg(__unit),
                        ::hilti::rt::resumable::detail::copyArg(__data), ::hilti::rt::resumable::detail::copyArg(__cur),
                        ::hilti::rt::resumable::detail::copyArg(__context));
    auto args_on_heap = std::make_shared<decltype(args)>(std::move(args));
    auto cb = [args_on_heap = std::move(args_on_heap)](::hilti::rt::resumable::Handle* r) -> ::hilti::rt::any {
        return __hlt_bench::Benchmark::WithUnit::parse2(std::get<0>(*args_on_heap), std::get<1>(*args_on_heap),
                                                        std::get<2>(*args_on_heap), std::get<3>(*args_on_heap));
    };

    auto r = std::make_unique<::hilti::rt::Resumable>(std::move(cb));
    r->run();
    return std::move(*r);
}

extern auto hlt_bench::Benchmark::WithUnit::parse3(::hilti::rt::ValueReference<::spicy::rt::ParsedUnit>& __gunit,
                                                   ::hilti::rt::ValueReference<::hilti::rt::Stream>& __data,
                                                   const std::optional<::hilti::rt::stream::View>& __cur,
                                                   const std::optional<::spicy::rt::UnitContext>& __context)
    -> ::hilti::rt::Resumable {
    auto args =
        std::make_tuple(::hilti::rt::resumable::detail::copyArg(__gunit),
                        ::hilti::rt::resumable::detail::copyArg(__data), ::hilti::rt::resumable::detail::copyArg(__cur),
                        ::hilti::rt::resumable::detail::copyArg(__context));
    auto args_on_heap = std::make_shared<decltype(args)>(std::move(args));
    auto cb = [args_on_heap = std::move(args_on_heap)](::hilti::rt::resumable::Handle* r) -> ::hilti::rt::any {
        return __hlt_bench::Benchmark::WithUnit::parse3(std::get<0>(*args_on_heap), std::get<1>(*args_on_heap),
                                                        std::get<2>(*args_on_heap), std::get<3>(*args_on_heap));
    };

    auto r = std::make_unique<::hilti::rt::Resumable>(std::move(cb));
    r->run();
    return std::move(*r);
}
