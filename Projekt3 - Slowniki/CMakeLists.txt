cmake_minimum_required(VERSION 3.27)
project(ISA_Struktury_Danych)

set(CMAKE_CXX_STANDARD 17)

add_executable(main.cpp
        HashTable_Bucket.h
        HashTable_Bucket.cpp
        utilities.cpp
        utilities.h
        main.cpp
)