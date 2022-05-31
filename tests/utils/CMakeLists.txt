set(target_name TestUtils)

add_library(
    ${target_name}
        Utils.cpp
)

target_include_directories(
    ${target_name}
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(
    ${target_name}
        PUBLIC
            dft
)
