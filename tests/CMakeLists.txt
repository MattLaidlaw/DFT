add_executable(
    TestDFT
        TestNaiveDFT.cpp
        Utils.cpp
)

target_link_libraries(
    TestDFT
        dft
        GTest::gtest_main
)

add_executable(
    BenchmarkDFT
        BenchmarkNaiveDFT.cpp
        Utils.cpp
)

target_link_libraries(
    BenchmarkDFT
        dft
        benchmark::benchmark_main
)
