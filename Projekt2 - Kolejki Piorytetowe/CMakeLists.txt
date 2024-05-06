cmake_minimum_required(VERSION 3.27)
project(ISA_Struktury_Danych)

set(CMAKE_CXX_STANDARD 17)

add_executable(ISA_Struktury_Danych PQheap.h
        PQheap.cpp
        main.cpp
        test.h
        test.h
        test.cpp
        ArrayPQueue.cpp)