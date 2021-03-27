cmake_minimum_required(VERSION 3.4...3.18)
project(cmake_example)

add_subdirectory(fraktal)
include_directories(fraktal)
add_subdirectory(pybind11)

pybind11_add_module(fraktal_py ${CMAKE_CURRENT_SOURCE_DIR}/fraktal_py/fraktal_py.cpp)

target_link_libraries(fraktal_py
    PRIVATE static-fraktal
)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(fraktal_py PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
