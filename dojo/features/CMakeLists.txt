# C++ language features exploration

# Experiments library - add experiment source files here
add_library(features_experiments SHARED
    _placeholder.cpp
    # Add experiment files below:
)

target_link_libraries(features_experiments
    PRIVATE
        cpp_dojo::dispatcher
)
