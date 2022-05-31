include(GoogleTest)

set(target_name TestDFT)

add_executable(
    ${target_name}
        TestFFT.cpp
        TestNaiveDFT.cpp
)

target_link_libraries(
    ${target_name}
        dft
        GTest::gtest_main
        TestUtils
)

gtest_discover_tests(${target_name})
