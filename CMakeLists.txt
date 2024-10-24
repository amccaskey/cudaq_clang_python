cmake_minimum_required(VERSION 3.18)
project(cuda_q_pybind_example LANGUAGES CXX CUDA)

# Find required packages
set(CUDAQ_LIBRARY_MODE ON)

find_package(CUDAQ REQUIRED)
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

# Include FetchContent
include(FetchContent)

# Declare pybind11 dependency
# FetchContent_Declare(
#     pybind11
#     GIT_REPOSITORY https://github.com/pybind/pybind11
#     GIT_TAG v2.11.1
# )
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11
    GIT_TAG 8b48ff878c168b51fe5ef7b8c728815b9e1a9857
)

# Make pybind11 available
FetchContent_MakeAvailable(pybind11)


# Add include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Create the pybind11 module
pybind11_add_module(noise_model_wrapper 
    src/noise_wrapper.cpp
    src/bindings.cpp
)

# Link against CUDA libraries
target_link_libraries(noise_model_wrapper PRIVATE 
    cudaq::cudaq 
)

# Set output directory
set_target_properties(noise_model_wrapper PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/python
)