#!/usr/bin/env ruby

# This can only be called if bench_Benchmark.cc is in a clean state
if `git diff --name-only`.split("\n").include?("sequential/bench_Benchmark.cc")
  puts "Cannot run unless bench_Benchmark.cc is in a clean state"
  exit(1)
end

def build_benchmark(patch = nil)
  Dir.mkdir("build") unless Dir.exist?("build")

  # Make the initial binary
  compiler = `spicy-config --cxx`.chomp
  compile_command = `spicy-config --cxxflags --ldflags`.chomp

  out = "build/spicy-bench"
  if patch
    patch_num = patch[0, 4]
    out += "_#{patch_num}"
  end

  cxx_command = "#{compiler} -o #{out} bench.cc bench___linker__.cc bench_Benchmark.cc #{compile_command}"
  system(cxx_command)
  if $?.exitstatus != 0
    puts "Compilation failed!"
    exit
  end

  return out
end


binaries = [build_benchmark]

# Then one for each patch
Dir.each_child("patches").sort.each do |patch|
  puts patch
  system("git apply patches/#{patch}")
  binaries << build_benchmark(patch)
end

binaries.each do |binary|
  avg = `#{binary}`
  puts "#{binary}: #{avg}"
end
