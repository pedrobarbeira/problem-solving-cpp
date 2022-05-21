cmake_minimum_required(VERSION 3.21)
project(problemsolvcpp)

set(CMAKE_CXX_STANDARD 23)

include_directories(src
        src/chapter1 src/chapter2
        src/chapter3 src/chapter4
        src/chapter5 src/chapter6
        src/chapter7 src/chapter14)

add_executable(problemsolvcpp main.cpp
        src/chapter1/chapter1.h src/chapter1/chapter1.cpp
        src/chapter2/chapter2.h src/chapter2/chapter2.cpp
        src/chapter3/chapter3.h src/chapter3/chapter3.cpp
        src/chapter4/chapter4.h src/chapter4/chapter4.cpp
        src/chapter5/chapter5.h src/chapter5/chapter5.cpp
        src/chapter6/chapter6.h src/chapter6/chapter6.cpp
        src/chapter7/chapter7.h src/chapter7/chapter7.cpp src/chapter14/chapter14.cpp src/chapter14/chapter14.h)


