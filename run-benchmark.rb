#!/usr/bin/env ruby

Dir.mkdir("build") unless Dir.exist?("build")

Dir.chdir("build") do
  system("spicyc -P bench ../custom.spicy -o bench.h")
  if $?.exitstatus != 0
    puts "Spicyc failed!"
    exit
  end
  system("spicyc -x bench ../custom.spicy")
  if $?.exitstatus != 0
    puts "Spicyc failed!"
    exit
  end

  compile_command = `spicy-config --cxx --cxxflags --ldflags`.chomp
  cxx_command = "#{compile_command} -I . -o bench ../bench.cc bench___linker__.cc bench_Benchmark.cc"
  system(cxx_command)
  if $?.exitstatus != 0
    puts "Compilation failed!"
    exit
  end

  puts "\n" * 2
  puts "Running benchmarks!"
  puts "\n"

  system("../bench")
end
