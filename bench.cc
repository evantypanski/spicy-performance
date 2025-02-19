#include "bench.h"

#include <ctime>
#include <initializer_list>
#include <iostream>
#include <numeric>

#include <hilti/rt/libhilti.h>

#include <spicy/rt/libspicy.h>

constexpr uint64_t samples = 5;

std::string big_endian(std::uint64_t number) {
    char buffer[8];

    // shrug
    buffer[0] = (number >> 56) & 0xFF;
    buffer[1] = (number >> 48) & 0xFF;
    buffer[2] = (number >> 40) & 0xFF;
    buffer[3] = (number >> 32) & 0xFF;
    buffer[4] = (number >> 24) & 0xFF;
    buffer[5] = (number >> 16) & 0xFF;
    buffer[6] = (number >> 8) & 0xFF;
    buffer[7] = number & 0xFF;

    return std::string(buffer, sizeof(buffer));
}

std::string make_input() {
    std::uint64_t N = 100000000;
    std::string number = big_endian(N);
    std::string repeated(N, 'A');
    return number + repeated + 'B' + 'B';
}

using ParseFunction = std::function<::hilti::rt::Resumable(::hilti::rt::ValueReference<::hilti::rt::Stream>&,
                                                           const std::optional<::hilti::rt::stream::View>&,
                                                           const std::optional<::spicy::rt::UnitContext>&)>;

auto time_parser(std::string data, ParseFunction parse_func) {
    auto stream = hilti::rt::reference::make_value<hilti::rt::Stream>(data);
    stream->freeze();

    std::clock_t start = std::clock();
    parse_func(stream, {}, {});
    std::clock_t end = std::clock();

    return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

auto run_benchmarks(std::initializer_list<std::pair<std::string, ParseFunction>> benchmarks) {
    hilti::rt::init();

    auto input = make_input();
    std::map<std::string, std::array<double, samples>> sampled;
    for ( const auto& [name, parse_func] : benchmarks )
        sampled[name] = {};

    for ( const auto& [name, parse_func] : benchmarks ) {
        std::cout << "\r" << std::string(30, ' ') << "\r";
        std::cout << "Sampling " << name << "\n";
        for ( uint64_t i = 0; i < samples; i++ ) {
            std::cout << "\rSampling " << i + 1 << "/" << samples << "..." << std::flush;
            sampled[name][i] = time_parser(input, parse_func);
        }
        std::cout << "\r" << std::flush;
    }

    hilti::rt::done();

    return sampled;
}

int main(int argc, char** argv) {
    std::initializer_list<std::pair<std::string, ParseFunction>> to_benchmark =
        {{"BytesLength", hlt_bench::Benchmark::BytesLength::parse1},
         {"BytesUntil", hlt_bench::Benchmark::BytesUntil::parse1},
         {"While", hlt_bench::Benchmark::While::parse1},
         {"Regex", hlt_bench::Benchmark::Regex::parse1},
         {"WithUnit", hlt_bench::Benchmark::WithUnit::parse1},
         {"WithUnitSwitch", hlt_bench::Benchmark::WithUnitSwitch::parse1},
         {"Sync", hlt_bench::Benchmark::Sync::parse1},
         {"SyncRegex", hlt_bench::Benchmark::SyncRegex::parse1}};

    auto results = run_benchmarks(to_benchmark);

    std::cout << "Done sampling!\n\n";
    std::cout << std::setw(15) << "Unit" << " | ";
    for ( uint64_t i = 0; i < samples; ++i )
        std::cout << "Sample " << i + 1 << " | ";

    std::cout << "Mean\n";

    std::cout << std::string(30 + (samples * 10), '-') << std::endl;

    // We'll calculate averages when making the table and use it in a second
    std::vector<std::pair<std::string, double>> averages;
    for ( const auto& [unit, times] : results ) {
        std::cout << std::setw(15) << unit << " | ";

        for ( const auto& time : times )
            std::cout << std::setw(8) << std::fixed << std::setprecision(3) << time << " | ";

        // Mean
        auto average = std::accumulate(times.begin(), times.end(), 0.0) / samples;
        averages.emplace_back(unit, average);
        std::cout << average;
        std::cout << "\n";
    }

    std::sort(averages.begin(), averages.end(), [](const auto& a, const auto& b) { return a.second < b.second; });

    std::cout << "\n\nResults in order:\n";
    for ( const auto& [name, avg] : averages )
        std::cout << std::setw(15) << name << ": " << avg << "\n";

    return 0;
}
