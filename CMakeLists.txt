cmake_minimum_required(VERSION 3.19)
project(NeuralNetC__)

set(CMAKE_CXX_STANDARD 20)

add_library(NET
        Neuron.hpp
        Math.hpp)
set_target_properties(NET PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(NET PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(NeuralNetC__ main.cpp)
target_link_libraries(NeuralNetC__ PUBLIC NET)