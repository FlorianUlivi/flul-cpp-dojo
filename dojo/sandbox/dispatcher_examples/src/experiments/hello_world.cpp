#include <iostream>

#include <experiment_registry.hpp>

namespace {

struct RegisterHelloWorld {
    RegisterHelloWorld() {
        cpp_dojo::ExperimentRegistry::Builder("Hello World").Execute([]() {
            std::cout << "Hello from experiment: hello_world" << '\n';
        });
    }
} register_hello_world;

}  // namespace
