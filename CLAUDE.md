# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build

```bash
cmake --preset debug
cmake --build --preset debug
```

## Test

```bash
ctest --preset debug
```

## Single Test

```bash
cmake --build build/debug --target <name>_test
```

## Run All Experiments

```bash
./build/debug/core/runner/runner
```

## Presets

```bash
cmake --preset debug     # Debug build
cmake --preset release   # Release build
```

## Structure

- `core/` - Shared infrastructure
  - `dispatcher/` - Experiment registry library
  - `runner/` - Central executable that runs all experiments
- `dojo/` - Experiment categories
  - `features/` - C++ language features
  - `patterns/` - Design patterns
  - `katas/` - Programming challenges
  - `sandbox/` - Freeform exploration

Each category directory builds a shared library (`<category>_experiments`) that the runner links.

## Adding an Experiment

An "experiment" is any code that registers with the dispatcher, regardless of which folder it lives in.

1. Create your experiment file in the appropriate category folder:

```cpp
// dojo/features/concepts/my_experiment.cpp
#include <iostream>

#include <experiment_registry.hpp>

namespace {

struct RegisterMyExperiment {
    RegisterMyExperiment() {
        flul_cpp_dojo::ExperimentRegistry::Builder("My Experiment").Execute([]() {
            std::cout << "Hello from my experiment\n";
        });
    }
} register_my_experiment;

}  // namespace
```

2. Add the file to the category's `CMakeLists.txt`:

```cmake
add_library(features_experiments SHARED
    _placeholder.cpp
    concepts/my_experiment.cpp  # Add here
)
```

3. Rebuild and run:

```bash
cmake --build --preset debug
./build/debug/core/runner/runner
```

## CMake Guidelines

- **Always list source files explicitly** in CMakeLists.txt - never use file globbing/discovery
- Each category has a `<category>_experiments` shared library
- The runner links all category libraries - no changes needed when adding experiments

## Code Style

This project follows the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).

### Naming Conventions

- **Types** (classes, structs, enums, type aliases): `CamelCase`
- **Functions/Methods**: `CamelCase`
- **Variables**: `snake_case`
- **Class members**: `snake_case_` (trailing underscore)
- **Constants**: `kCamelCase` (leading k)
- **Macros**: `SCREAMING_SNAKE_CASE`
- **Namespaces**: `snake_case`

### Tooling

- **clang-format**: Run `clang-format -i <file>` to format code
- **clang-tidy**: Run `./scripts/clang-tidy.sh <file>` for static analysis and naming checks

### Project Overrides

The following deviate from pure Google style (see `.clang-format`):

- Indent width: 4 spaces (Google uses 2)
- Column limit: 100 (Google uses 80)
- Pointer alignment: Left (Google uses Right)

### Comments

- Only use comments to explain why something is done, if it is not obvious, rather than what is done. The code should explain what is happening.
