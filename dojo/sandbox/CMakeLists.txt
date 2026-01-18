# Freeform exploration area

# Experiments library - add experiment source files here
add_library(sandbox_experiments SHARED
    _placeholder.cpp
    # Add experiment files below:
)

target_link_libraries(sandbox_experiments
    PRIVATE
        cpp_dojo::dispatcher
)
