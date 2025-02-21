#include <ctime>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>

#include "test_pac.h"

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

using ParseFunction = std::function<void(bool, binpac::const_byteptr, binpac::const_byteptr)>;

template<typename Conn>
auto time_parser(std::string data, Conn conn) {
    const binpac::uint8* input_arr = (const unsigned char*)data.c_str();
    const binpac::uint8* input_end = input_arr + data.length() + 1;

    std::clock_t start = std::clock();
    conn.NewData(true, input_arr, input_end);
    std::clock_t end = std::clock();

    return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

int main(int argc, char** argv) {
    auto input = make_input();
    std::map<std::string, std::array<double, samples>> results;
    // I don't feel like doing template shenanigans for binpac right now
    results["WithRecord"] = {};
    std::cout << "\r" << std::string(30, ' ') << "\r";
    std::cout << "Sampling " << "WithRecord" << "\n";

    for ( uint64_t i = 0; i < samples; i++ ) {
        std::cout << "\rSampling " << i + 1 << "/" << samples << "..." << std::flush;
        // Binpac keeps trying to free statically allocated stuff so this is dynamic :)
        binpac::WithRecord::WithRecordConn* conn = new binpac::WithRecord::WithRecordConn();
        results["WithRecord"][i] = time_parser(input, *conn);
        std::cout << results["WithRecord"][i];
    }
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
