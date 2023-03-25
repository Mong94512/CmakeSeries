cmake_minimum_required(VERSION 3.0)
project(HelloApp
        VERSION 0.0.1
        DESCRIPTION "The leading Hello World App
        LANGUAGE CXX")

#Target
add_executable(haching main.cpp function.cpp)
target_compile_features(haching PRIVATE cxx_std_20)
target_include_directories(haching PRIVATE ../include)

