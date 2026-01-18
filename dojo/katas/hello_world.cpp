#include <iostream>

#include <experiment_registry.hpp>

namespace {

void hello_world() {
    std::cout << "Hello world!\n";       // English
    std::cout << "Bonjour le monde!\n";  // French
    std::cout << "Hallo Welt!\n";        // German
    std::cout << "¡Hola mundo!\n";       // Spanish
    std::cout << "Ciao mondo!\n";        // Italian
}

struct RegisterHelloWorld {
    RegisterHelloWorld() {
        flul_cpp_dojo::ExperimentRegistry::Builder("Hello world").Execute(&hello_world);
    }
} register_hello_world;

}  // namespace
