# Design patterns and idioms

# Experiments library - add experiment source files here
add_library(patterns_experiments SHARED
    _placeholder.cpp
    # Add experiment files below:
)

target_link_libraries(patterns_experiments
    PRIVATE
        flul_cpp_dojo::dispatcher
)
