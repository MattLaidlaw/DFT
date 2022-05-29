# DFT

## Description
This project implements a variety of Discrete Fourier Transform algorithms.
These algorithms are tested for accuracy and benchmarked to identify throughput and computational complexity.

## Requirements
* CMake >= 3.22

## Building
```commandline
git submodule update --init --recursive
mkdir build
cmake -B build .
cmake --build build
```

## Running Tests
```commandLine
./build/tests/TestDFT
```

## Running Benchmarks
```commandline
./build/tests/BenchmarkDFT
```

## Benchmark Example
Below is the Google Benchmark output run on the Naive DFT implementation.
We can see the algorithm has been run with a variety of input sizes.
We can also see throughput values for each run in bytes/second.
Finally, we can see an estimated Big O value, correctly estimating the Naive DFT algorithm at O(N^2).
```commandLine
2022-05-28T20:12:50-07:00
Running C:\Users\mlaid\CLionProjects\DFT\cmake-build-release\tests\BenchmarkDFT.exe
Run on (8 X 3627.59 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x8)
  L1 Instruction 32 KiB (x8)
  L2 Unified 256 KiB (x8)
  L3 Unified 12288 KiB (x1)
-------------------------------------------------------------------------------------------
Benchmark                                 Time             CPU   Iterations UserCounters...
-------------------------------------------------------------------------------------------
Benchmark_NaiveDFT_Forward/1024    13662042 ns     10986328 ns           64 bytes_per_second=91.0222k/s
Benchmark_NaiveDFT_Forward/2048    54686764 ns     49107143 ns           14 bytes_per_second=40.7273k/s
Benchmark_NaiveDFT_Forward/4096   218659125 ns    175781250 ns            4 bytes_per_second=22.7556k/s
Benchmark_NaiveDFT_Forward/8192   874592200 ns    671875000 ns            1 bytes_per_second=11.907k/s
Benchmark_NaiveDFT_Forward/16384 3510606300 ns   2531250000 ns            1 bytes_per_second=6.32099k/s
Benchmark_NaiveDFT_Forward/32768 1.4095e+10 ns   1.1594e+10 ns            1 bytes_per_second=2.76011k/s
Benchmark_NaiveDFT_Forward_BigO       13.12 N^2       10.71 N^2  
Benchmark_NaiveDFT_Forward_RMS            0 %             6 %
```
