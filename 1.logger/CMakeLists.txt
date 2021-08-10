cmake_minimum_required(VERSION 2.8.9)
project (logger)

set(CMAKE_BUILD_TYPE Debug)

find_package (Threads)

add_executable(logger_test src/main.cpp src/StdLogger.cpp src/FileLogger.cpp src/LogManager.cpp src/ILogger.cpp)

set_target_properties(logger_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY bin)

target_link_libraries (logger_test ${CMAKE_THREAD_LIBS_INIT})