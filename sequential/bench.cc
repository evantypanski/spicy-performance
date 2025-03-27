#include "bench.h"

#include <ctime>
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

int main(int argc, char** argv) {
    hilti::rt::init();

    auto input = make_input();
    std::array<double, samples> sampled;

    std::cout << "\r" << std::string(30, ' ') << "\r";
    for ( uint64_t i = 0; i < samples; i++ ) {
        std::cout << "\rSampling " << i + 1 << "/" << samples << "..." << std::flush;
        sampled[i] = time_parser(input, hlt_bench::Benchmark::WithUnit::parse1);
    }
    hilti::rt::done();

    std::cout << "\r" << std::flush;
    std::cout << "                            \r" << std::flush;

    std::cout << "Mean: " << std::accumulate(sampled.begin(), sampled.end(), 0.0) / samples << "\n";

    return 0;
}
