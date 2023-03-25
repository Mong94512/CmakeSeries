cmake_minimum_required(VERSION 3.0)
project(HelloApp
        VERSION 0.0.1
        DESCRIPTION "The leading Hello World App
        LANGUAGE CXX")
add_executable(HelloAppBinary main.cpp)
target_compile_features(HelloAppBinary PRIVATE cxx_std_20)