# Programming challenges

# Experiments library - add experiment source files here
add_library(katas_experiments SHARED
    _placeholder.cpp
    # Add experiment files below:
    hello_world.cpp
)

target_link_libraries(katas_experiments
    PRIVATE
        flul_cpp_dojo::dispatcher
)
