cmake_minimum_required(VERSION 3.27)
project(ISA_Struktury_Danych)

set(CMAKE_CXX_STANDARD 17)

add_executable(HashTable.h
        HashTable_Bucket.h
        HashTable_Bucket.cpp
        main.cpp
        HashTable_Cuckoo.h
        HashTable_Cuckoo.cpp
        tests.h
        tests.cpp
        HashTable_Open.h
        HashTable_Open.cpp
)