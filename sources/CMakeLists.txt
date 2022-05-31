set(target_name dft)

add_library(${target_name}
    FFT.cpp
    NaiveDFT.cpp
)

target_include_directories(
    ${target_name}
        PUBLIC
            ${PROJECT_SOURCE_DIR}/includes
)
