#!/bin/bash
# Post-hook: Auto-format C++ files after Edit/Write

# Read file path from JSON input
file_path=$(jq -r '.tool_input.file_path // empty')

# Exit early if no file path
[[ -z "$file_path" ]] && exit 0

# Check if it's a C++ file
case "$file_path" in
    *.cpp|*.cc|*.cxx|*.h|*.hpp|*.hxx)
        clang-format -i "$file_path" 2>/dev/null
        ;;
esac

exit 0
