set(target_name BenchmarkDFT)

add_executable(
    ${target_name}
        BenchmarkFFT.cpp
        BenchmarkNaiveDFT.cpp
)

target_link_libraries(
    ${target_name}
        dft
        benchmark::benchmark_main
        TestUtils
)
