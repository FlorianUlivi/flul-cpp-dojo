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

## Presets

```bash
cmake --preset debug     # Debug build
cmake --preset release   # Release build
```

## Structure

- `features/` - C++ language features
- `patterns/` - Design patterns
- `katas/` - Programming challenges
- `experiments/` - Freeform exploration

Each directory contains independent sub-projects. See README.md for detailed workflow.

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
