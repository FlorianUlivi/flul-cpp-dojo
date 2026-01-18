# Experiment Dispatcher Library
# Header-only library for experiment registration and execution

add_library(dispatcher INTERFACE)
add_library(cpp_dojo::dispatcher ALIAS dispatcher)

target_include_directories(dispatcher
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(dispatcher INTERFACE cxx_std_23)

# Unit tests
add_executable(dispatcher_test
    test/experiment_registry_test.cpp
)

target_link_libraries(dispatcher_test
    PRIVATE
        dispatcher
        GTest::gtest
        GTest::gtest_main
)

gtest_discover_tests(dispatcher_test)
