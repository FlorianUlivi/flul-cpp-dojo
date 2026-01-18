#include <experiment_registry.hpp>

int main() {
    cpp_dojo::ExperimentRegistry::Instance().RunAll();
    return 0;
}
