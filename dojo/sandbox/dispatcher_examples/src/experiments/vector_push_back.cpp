#include <iostream>
#include <vector>

#include <experiment_registry.hpp>

namespace {

struct RegisterVectorPushBack {
    RegisterVectorPushBack() {
        cpp_dojo::ExperimentRegistry::Builder("Vector Push Back").Execute([]() {
            std::vector<int> numbers;
            numbers.push_back(1);
            numbers.push_back(2);
            numbers.push_back(3);
            numbers.push_back(4);
            numbers.push_back(5);

            std::cout << "Vector contents: ";
            for (std::size_t i = 0; i < numbers.size(); ++i) {
                if (i > 0) {
                    std::cout << " ";
                }
                std::cout << numbers[i];
            }
            std::cout << '\n';
        });
    }
} register_vector_push_back;

}  // namespace
