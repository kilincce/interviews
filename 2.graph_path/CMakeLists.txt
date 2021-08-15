cmake_minimum_required(VERSION 2.8.9)
project (graph_path)

set(CMAKE_BUILD_TYPE Debug)

add_executable(graph_path src/Solution.cpp)

set_target_properties(graph_path PROPERTIES RUNTIME_OUTPUT_DIRECTORY bin)
