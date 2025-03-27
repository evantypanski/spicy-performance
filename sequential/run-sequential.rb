#!/usr/bin/env ruby

compiler = `spicy-config --cxx`.chomp
compile_command = `spicy-config --cxxflags --ldflags`.chomp
cxx_command = "#{compiler} -o spicy-bench bench.cc bench___linker__.cc bench_Benchmark.cc #{compile_command}"
system(cxx_command)
if $?.exitstatus != 0
  puts "Compilation failed!"
  exit
end

puts "\n" * 2
puts "Running initial Spicy benchmark!"
puts "\n"

system("./spicy-bench")
