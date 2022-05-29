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
We can see the algorithm has been run with a variety of input sizes: 8, 64, 512, 4096, 8192.
We can also see throughput values for each run.
Finally, we can see an estimated Big O value, correctly estimating the Naive DFT algorithm at O(N^2).
```commandLine
------------------------------------------------------------------------------------------
Benchmark                                Time             CPU   Iterations UserCounters...
------------------------------------------------------------------------------------------
Benchmark_NaiveDFT_Forward/8          5122 ns         2340 ns       407273 bytes_per_second=3.26006M/s
Benchmark_NaiveDFT_Forward/64       256151 ns        92072 ns         7467 bytes_per_second=678.818k/s
Benchmark_NaiveDFT_Forward/512    16101548 ns      6718750 ns          100 bytes_per_second=74.4186k/s
Benchmark_NaiveDFT_Forward/4096 1045653200 ns    593750000 ns            1 bytes_per_second=6.73684k/s
Benchmark_NaiveDFT_Forward/8192 4116176400 ns   2125000000 ns            1 bytes_per_second=3.76471k/s
Benchmark_NaiveDFT_Forward_BigO      61.39 N^2       31.88 N^2  
Benchmark_NaiveDFT_Forward_RMS           1 %             5 %
```
