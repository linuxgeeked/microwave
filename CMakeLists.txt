cmake_minimum_required(VERSION 3.16)
project(microwave_calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(microwave_calculator
    src/main.cpp
    src/heat.cpp
    src/cool.cpp
    src/nuke.cpp
    src/burn_chicken.cpp
    src/microwave_control_panel.cpp
)

target_include_directories(microwave_calculator PRIVATE include)

add_executable(microwave_tests
    tests/microwave_test.cpp
    src/heat.cpp
    src/cool.cpp
    src/nuke.cpp
    src/burn_chicken.cpp
)

target_include_directories(microwave_tests PRIVATE include)

enable_testing()
add_test(NAME microwave_diagnostic_cycle COMMAND microwave_tests)
