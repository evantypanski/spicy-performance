#!/usr/bin/env ruby


# Binpac stuff ;) Hacky, of course
# Note that this requires removing the regex dependency in binpac because that depends on
# Zeek's regex
binpac_enabled = true;
binpac_includes = "-I $HOME/src/binpac/build/lib -I $HOME/src/binpac/lib"

spicy_enabled = false;

Dir.mkdir("build") unless Dir.exist?("build")

if binpac_enabled
  Dir.chdir("binpac") do
    system("binpac test.pac")
  end
  # This is dumb. I can't figure out how to get the binpac executable to move stuff to a
  # different directory. -d just says "No such file or directory" yeah cool.
  require 'fileutils'
  FileUtils.mv("binpac/test_pac.cc", "build")
  FileUtils.mv("binpac/test_pac.h", "build")
end


Dir.chdir("build") do
  if spicy_enabled
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

    compiler = `spicy-config --cxx`.chomp
    compile_command = `spicy-config --cxxflags --ldflags`.chomp
    cxx_command = "#{compiler} -I . -o bench ../bench.cc bench___linker__.cc bench_Benchmark.cc #{compile_command}"
    system(cxx_command)
    if $?.exitstatus != 0
      puts "Compilation failed!"
      exit
    end

    puts "\n" * 2
    puts "Running Spicy benchmarks!"
    puts "\n"

    system("./spicy-bench")
  end

  if binpac_enabled
    # Just assume the binpac compile command, I don't care enough
    system("clang++ ../bench_binpac.cc test_pac.cc -I . #{binpac_includes} -o binpac-bench")

    puts "\n" * 2
    puts "Running Binpac benchmarks!"
    puts "\n"

    system("./binpac-bench")
  end
end
