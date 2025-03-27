// Prototypes for module Benchmark

#ifndef HILTI_PROTOTYPES_BENCHMARK_H
#define HILTI_PROTOTYPES_BENCHMARK_H

#include <spicy/rt/libspicy.h>
#include <hilti/rt/libhilti.h>

extern const char* __hlt_bench_hlto_scope;

namespace __hlt_bench::Benchmark {
    struct Inner;
    struct WithUnit;
    struct Inner : ::hilti::rt::trait::isStruct, ::hilti::rt::Controllable<Inner> {
        auto __self() { return ::hilti::rt::ValueReference<Inner>::self(this); }
        std::optional<::hilti::rt::integer::safe<uint8_t>> b{};
        auto __parse_stage1(::hilti::rt::ValueReference<::hilti::rt::Stream>& __data, const ::hilti::rt::stream::SafeConstIterator& __begin, ::hilti::rt::stream::View __cur, ::hilti::rt::Bool __trim, ::hilti::rt::integer::safe<int64_t> __lah, ::hilti::rt::stream::SafeConstIterator __lahe, std::optional<::hilti::rt::RecoverableFailure> __error) -> std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>, ::hilti::rt::stream::SafeConstIterator, std::optional<::hilti::rt::RecoverableFailure>>;
        auto __parse_Benchmark__Inner_stage2(::hilti::rt::ValueReference<::hilti::rt::Stream>& __data, const ::hilti::rt::stream::SafeConstIterator& __begin, ::hilti::rt::stream::View __cur, ::hilti::rt::Bool __trim, ::hilti::rt::integer::safe<int64_t> __lah, ::hilti::rt::stream::SafeConstIterator __lahe, std::optional<::hilti::rt::RecoverableFailure> __error) -> std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>, ::hilti::rt::stream::SafeConstIterator, std::optional<::hilti::rt::RecoverableFailure>>;
        std::optional<::hilti::rt::RecoverableFailure> __error{};
        Inner();
        Inner(const Inner&) = default;
        Inner(Inner&&) = default;
        Inner& operator=(const Inner&) = default;
        Inner& operator=(Inner&&) = default;
        Inner(std::optional<std::optional<::hilti::rt::integer::safe<uint8_t>>> b);
        template<typename F> void __visit(F _) const { _("b", b); }

        std::string __to_string() const {
            return "["s + "$b=" + hilti::rt::to_string(b) + "]";
        }
    };

    struct WithUnit : ::hilti::rt::trait::isStruct, ::hilti::rt::Controllable<WithUnit> {
        auto __self() { return ::hilti::rt::ValueReference<WithUnit>::self(this); }
        std::optional<::hilti::rt::integer::safe<uint64_t>> length{};
        std::optional<::hilti::rt::Vector<Inner>> inner{};
        std::optional<::hilti::rt::Bytes> end_{};
        inline static ::spicy::rt::Parser __parser{};
        auto __parse_stage1(::hilti::rt::ValueReference<::hilti::rt::Stream>& __data, const ::hilti::rt::stream::SafeConstIterator& __begin, ::hilti::rt::stream::View __cur, ::hilti::rt::Bool __trim, ::hilti::rt::integer::safe<int64_t> __lah, ::hilti::rt::stream::SafeConstIterator __lahe, std::optional<::hilti::rt::RecoverableFailure> __error) -> std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>, ::hilti::rt::stream::SafeConstIterator, std::optional<::hilti::rt::RecoverableFailure>>;
        static auto parse1(::hilti::rt::ValueReference<::hilti::rt::Stream>& __data, const std::optional<::hilti::rt::stream::View>& __cur, const std::optional<::spicy::rt::UnitContext>& __context) -> ::hilti::rt::stream::View;
        static auto parse2(::hilti::rt::ValueReference<WithUnit>& __unit, ::hilti::rt::ValueReference<::hilti::rt::Stream>& __data, const std::optional<::hilti::rt::stream::View>& __cur, const std::optional<::spicy::rt::UnitContext>& __context) -> ::hilti::rt::stream::View;
        static auto parse3(::hilti::rt::ValueReference<::spicy::rt::ParsedUnit>& __gunit, ::hilti::rt::ValueReference<::hilti::rt::Stream>& __data, const std::optional<::hilti::rt::stream::View>& __cur, const std::optional<::spicy::rt::UnitContext>& __context) -> ::hilti::rt::stream::View;
        auto __parse_inner_stage1(::hilti::rt::ValueReference<::hilti::rt::Stream>& __data, const ::hilti::rt::stream::SafeConstIterator& __begin, ::hilti::rt::stream::View __cur, ::hilti::rt::Bool __trim, ::hilti::rt::integer::safe<int64_t> __lah, ::hilti::rt::stream::SafeConstIterator __lahe, std::optional<::hilti::rt::RecoverableFailure> __error, ::hilti::rt::Vector<Inner>& __dst) -> std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>, ::hilti::rt::stream::SafeConstIterator, std::optional<::hilti::rt::RecoverableFailure>>;
        auto __parse_Benchmark__WithUnit_stage2(::hilti::rt::ValueReference<::hilti::rt::Stream>& __data, const ::hilti::rt::stream::SafeConstIterator& __begin, ::hilti::rt::stream::View __cur, ::hilti::rt::Bool __trim, ::hilti::rt::integer::safe<int64_t> __lah, ::hilti::rt::stream::SafeConstIterator __lahe, std::optional<::hilti::rt::RecoverableFailure> __error) -> std::tuple<::hilti::rt::stream::View, ::hilti::rt::integer::safe<int64_t>, ::hilti::rt::stream::SafeConstIterator, std::optional<::hilti::rt::RecoverableFailure>>;
        std::optional<::hilti::rt::RecoverableFailure> __error{};
        WithUnit();
        WithUnit(const WithUnit&) = default;
        WithUnit(WithUnit&&) = default;
        WithUnit& operator=(const WithUnit&) = default;
        WithUnit& operator=(WithUnit&&) = default;
        WithUnit(std::optional<std::optional<::hilti::rt::integer::safe<uint64_t>>> length, std::optional<std::optional<::hilti::rt::Vector<Inner>>> inner, std::optional<std::optional<::hilti::rt::Bytes>> end_);
        template<typename F> void __visit(F _) const { _("length", length); _("inner", inner); _("end_", end_); }

        std::string __to_string() const {
            return "["s + "$length=" + hilti::rt::to_string(length) + ", " "$inner=" + hilti::rt::to_string(inner) + ", " "$end_=" + hilti::rt::to_string(end_) + "]";
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
}

namespace hlt_bench::Benchmark::WithUnit {
    using Type = __hlt_bench::Benchmark::WithUnit;
}

namespace __hlt_bench::Benchmark {
    extern auto operator<<(std::ostream& o, const __hlt_bench::Benchmark::Inner& x) -> std::ostream&;
    extern auto operator<<(std::ostream& o, const __hlt_bench::Benchmark::WithUnit& x) -> std::ostream&;
}

namespace hlt_bench::Benchmark::WithUnit {
    extern auto parse1(::hilti::rt::ValueReference<::hilti::rt::Stream>& __data, const std::optional<::hilti::rt::stream::View>& __cur, const std::optional<::spicy::rt::UnitContext>& __context) -> ::hilti::rt::Resumable;
    extern auto parse2(::hilti::rt::ValueReference<__hlt_bench::Benchmark::WithUnit>& __unit, ::hilti::rt::ValueReference<::hilti::rt::Stream>& __data, const std::optional<::hilti::rt::stream::View>& __cur, const std::optional<::spicy::rt::UnitContext>& __context) -> ::hilti::rt::Resumable;
    extern auto parse3(::hilti::rt::ValueReference<::spicy::rt::ParsedUnit>& __gunit, ::hilti::rt::ValueReference<::hilti::rt::Stream>& __data, const std::optional<::hilti::rt::stream::View>& __cur, const std::optional<::spicy::rt::UnitContext>& __context) -> ::hilti::rt::Resumable;
}

namespace __hlt_bench::Benchmark {
    extern void __register_Benchmark_Inner();
    extern void __register_Benchmark_WithUnit();
    extern void __init_module();
    extern void __register_module();
}

namespace __hlt_bench::type_info { namespace {
    extern const ::hilti::rt::TypeInfo __ti_Benchmark__Inner_namex2aBenchmark__Innerx2b;
    extern const ::hilti::rt::TypeInfo __ti_optional_spicy__RecoverableFailure__optionalx2anamex2ahilti__RecoverableFailurex2bx2b;
    extern const ::hilti::rt::TypeInfo __ti_hilti__RecoverableFailure_namex2ahilti__RecoverableFailurex2b;
    const ::hilti::rt::TypeInfo __ti_hilti__RecoverableFailure_namex2ahilti__RecoverableFailurex2b = { "hilti::RecoverableFailure", "hilti::RecoverableFailure", [](const void *self) { return hilti::rt::to_string(*reinterpret_cast<const ::hilti::rt::RecoverableFailure*>(self)); }, new ::hilti::rt::type_info::Exception() };
    const ::hilti::rt::TypeInfo __ti_optional_spicy__RecoverableFailure__optionalx2anamex2ahilti__RecoverableFailurex2bx2b = { {}, "optional<spicy::RecoverableFailure>", [](const void *self) { return hilti::rt::to_string(*reinterpret_cast<const std::optional<::hilti::rt::RecoverableFailure>*>(self)); }, new ::hilti::rt::type_info::Optional(&type_info::__ti_hilti__RecoverableFailure_namex2ahilti__RecoverableFailurex2b, ::hilti::rt::type_info::Optional::accessor<::hilti::rt::RecoverableFailure>()) };
    const ::hilti::rt::TypeInfo __ti_Benchmark__Inner_namex2aBenchmark__Innerx2b = { "Benchmark::Inner", "Benchmark::Inner", [](const void *self) { return hilti::rt::to_string(*reinterpret_cast<const __hlt_bench::Benchmark::Inner*>(self)); }, new ::hilti::rt::type_info::Struct(std::vector<::hilti::rt::type_info::struct_::Field>({::hilti::rt::type_info::struct_::Field{ "b", &::hilti::rt::type_info::uint8, offsetof(Benchmark::Inner, b), false, false, ::hilti::rt::type_info::struct_::Field::accessor_optional<::hilti::rt::integer::safe<uint8_t>>() }, ::hilti::rt::type_info::struct_::Field{ "__error", &type_info::__ti_optional_spicy__RecoverableFailure__optionalx2anamex2ahilti__RecoverableFailurex2bx2b, offsetof(Benchmark::Inner, __error), true, false }})) };
    extern const ::hilti::rt::TypeInfo __ti_Benchmark__WithUnit_namex2aBenchmark__WithUnitx2b;
    extern const ::hilti::rt::TypeInfo __ti_vector_Inner__vectorx2anamex2aBenchmark__Innerx2bx2b;
    const ::hilti::rt::TypeInfo __ti_vector_Inner__vectorx2anamex2aBenchmark__Innerx2bx2b = { {}, "vector<Inner>", [](const void *self) { return hilti::rt::to_string(*reinterpret_cast<const ::hilti::rt::Vector<__hlt_bench::Benchmark::Inner>*>(self)); }, new ::hilti::rt::type_info::Vector(&type_info::__ti_Benchmark__Inner_namex2aBenchmark__Innerx2b, ::hilti::rt::type_info::Vector::accessor<__hlt_bench::Benchmark::Inner>()) };
    const ::hilti::rt::TypeInfo __ti_Benchmark__WithUnit_namex2aBenchmark__WithUnitx2b = { "Benchmark::WithUnit", "Benchmark::WithUnit", [](const void *self) { return hilti::rt::to_string(*reinterpret_cast<const __hlt_bench::Benchmark::WithUnit*>(self)); }, new ::hilti::rt::type_info::Struct(std::vector<::hilti::rt::type_info::struct_::Field>({::hilti::rt::type_info::struct_::Field{ "length", &::hilti::rt::type_info::uint64, offsetof(Benchmark::WithUnit, length), false, false, ::hilti::rt::type_info::struct_::Field::accessor_optional<::hilti::rt::integer::safe<uint64_t>>() }, ::hilti::rt::type_info::struct_::Field{ "inner", &type_info::__ti_vector_Inner__vectorx2anamex2aBenchmark__Innerx2bx2b, offsetof(Benchmark::WithUnit, inner), false, false, ::hilti::rt::type_info::struct_::Field::accessor_optional<::hilti::rt::Vector<__hlt_bench::Benchmark::Inner>>() }, ::hilti::rt::type_info::struct_::Field{ "end_", &::hilti::rt::type_info::bytes, offsetof(Benchmark::WithUnit, end_), false, false, ::hilti::rt::type_info::struct_::Field::accessor_optional<::hilti::rt::Bytes>() }, ::hilti::rt::type_info::struct_::Field{ "__error", &type_info::__ti_optional_spicy__RecoverableFailure__optionalx2anamex2ahilti__RecoverableFailurex2bx2b, offsetof(Benchmark::WithUnit, __error), true, false }})) };
} }

#endif
