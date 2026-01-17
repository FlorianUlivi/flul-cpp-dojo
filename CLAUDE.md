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

- Only use comments to explain why something is done, if it is not obvious, rather than what is done. The code should explain what is happening.
