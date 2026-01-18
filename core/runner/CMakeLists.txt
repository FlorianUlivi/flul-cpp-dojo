# Experiment Runner
# Central executable that runs all registered experiments

add_executable(runner
    main.cpp
)

target_link_libraries(runner
    PRIVATE
        cpp_dojo::dispatcher
        features_experiments
        patterns_experiments
        katas_experiments
        sandbox_experiments
)
