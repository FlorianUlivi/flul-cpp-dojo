#include <iostream>
#include <string>

#include <experiment_registry.hpp>

namespace {

struct RegisterStringConcat {
    RegisterStringConcat() {
        cpp_dojo::ExperimentRegistry::Builder("String Concatenation").Execute([]() {
            std::string greeting = "Hello";
            std::string separator = ", ";
            std::string target = "World";
            std::string punctuation = "!";

            std::string result = greeting + separator + target + punctuation;
            std::cout << "Concatenated string: " << result << '\n';
        });
    }
} register_string_concat;

}  // namespace
