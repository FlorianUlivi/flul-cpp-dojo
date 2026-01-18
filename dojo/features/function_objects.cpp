#include <experiment_registry.hpp>
using Registry = flul_cpp_dojo::ExperimentRegistry;

namespace {

struct Adder {
    bool carry = false;

    bool operator()(bool input_a, bool input_b) {
        // For boolean != serves as XOR
        const auto intermediate = (input_a != input_b);
        const auto sum = intermediate != carry;
        carry = (intermediate && carry) || (input_a && input_b);
        return sum;
    }
};

struct RegisterFunctionObject {
    RegisterFunctionObject() {
        Registry::Builder("Function Object").Execute([] {
            auto adder = Adder();
            // Call like a function ...
            auto sum = adder(true, true);
            // ... and access the state
            if (!sum && adder.carry) {
                std::cout << "The adder worked as intended!\n";
            }
        });
    }
} register_function_object;

}  // namespace
