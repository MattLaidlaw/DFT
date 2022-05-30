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
Below is the Google Benchmark output comparing the NaiveDFT and FFT implementations.
We can see the algorithms have run with a variety of input sizes.
We can also see throughput values for each run in bytes/second.
Finally, we can see estimated Big O values, correctly placing the FFT algorithm at O(N * log(N))
and the Naive DFT algorithm at O(N^2).
```commandLine
2022-05-28T20:12:50-07:00
2022-05-30T11:00:37-07:00
Running C:\Users\mlaid\CLionProjects\DFT\cmake-build-release\tests\BenchmarkDFT.exe
Run on (8 X 3615.95 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x8)
  L1 Instruction 32 KiB (x8)
  L2 Unified 256 KiB (x8)
  L3 Unified 12288 KiB (x1)
-------------------------------------------------------------------------------------------
Benchmark                                 Time             CPU   Iterations UserCounters...
-------------------------------------------------------------------------------------------
Benchmark_FFT_Forward/1024           126823 ns       110905 ns         7467 bytes_per_second=8.80542M/s
Benchmark_FFT_Forward/2048           270312 ns       243121 ns         2635 bytes_per_second=8.03354M/s
Benchmark_FFT_Forward/4096           584143 ns       443339 ns         1445 bytes_per_second=8.81098M/s
Benchmark_FFT_Forward/8192          1233561 ns       920759 ns          560 bytes_per_second=8.48485M/s
Benchmark_FFT_Forward/16384         2551702 ns      2246094 ns          320 bytes_per_second=6.95652M/s
Benchmark_FFT_Forward/32768         5489548 ns      5312500 ns          100 bytes_per_second=5.88235M/s
Benchmark_FFT_Forward_BigO            11.18 NlgN      10.54 NlgN 
Benchmark_FFT_Forward_RMS                 1 %             8 %    
Benchmark_NaiveDFT_Forward/1024    13750942 ns     12187500 ns           50 bytes_per_second=82.0513k/s
Benchmark_NaiveDFT_Forward/2048    54891900 ns     50000000 ns           10 bytes_per_second=40k/s
Benchmark_NaiveDFT_Forward/4096   218636180 ns    200000000 ns            5 bytes_per_second=20k/s
Benchmark_NaiveDFT_Forward/8192   872469500 ns    718750000 ns            1 bytes_per_second=11.1304k/s
Benchmark_NaiveDFT_Forward/16384 3487494600 ns   3250000000 ns            1 bytes_per_second=4.92308k/s
Benchmark_NaiveDFT_Forward/32768 1.3966e+10 ns   1.2703e+10 ns            1 bytes_per_second=2.51907k/s
Benchmark_NaiveDFT_Forward_BigO       13.01 N^2       11.84 N^2  
Benchmark_NaiveDFT_Forward_RMS            0 %             2 %    

Process finished with exit code 0

```
