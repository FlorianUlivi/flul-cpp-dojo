# Programming challenges

# Standalone executables
add_executable(HelloWorld hello_world.cpp)

# Experiments library - add experiment source files here
add_library(katas_experiments SHARED
    _placeholder.cpp
    # Add experiment files below:
)

target_link_libraries(katas_experiments
    PRIVATE
        cpp_dojo::dispatcher
)
