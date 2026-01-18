# Freeform exploration area

# Standalone sub-projects
add_subdirectory(dispatcher_examples)

# Experiments library - add experiment source files here
add_library(sandbox_experiments SHARED
    _placeholder.cpp
    # Add experiment files below:
)

target_link_libraries(sandbox_experiments
    PRIVATE
        cpp_dojo::dispatcher
)
