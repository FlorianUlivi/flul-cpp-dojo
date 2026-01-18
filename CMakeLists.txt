cmake_minimum_required(VERSION 3.25)

project(flul-cpp-dojo
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/CompilerWarnings.cmake)

find_package(GTest CONFIG REQUIRED)

# Enable testing
enable_testing()
include(GoogleTest)

# Core infrastructure (shared libraries)
add_subdirectory(core)

# Experiment categories
add_subdirectory(dojo)
