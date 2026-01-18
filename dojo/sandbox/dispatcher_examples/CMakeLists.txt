# Dispatcher Examples Executable
# Demonstrates the experiment dispatcher framework

add_executable(dispatcher_examples
    src/main.cpp
    src/experiments/hello_world.cpp
    src/experiments/vector_push_back.cpp
    src/experiments/string_concat.cpp
)

target_link_libraries(dispatcher_examples
    PRIVATE
        cpp_dojo::dispatcher
)
