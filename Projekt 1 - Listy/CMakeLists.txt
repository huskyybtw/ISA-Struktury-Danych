cmake_minimum_required(VERSION 3.27)
project(ISA_Struktury_Danych)

set(CMAKE_CXX_STANDARD 17)

add_executable(ISA_Struktury_Danych main.cpp
        List.cpp
        List.h
        List.h
        List.cpp
        tests.cpp
        tests.h
        SNode.h
        DoublyList.cpp
        DoublyList.h
        DNode.h
        ArrayList.cpp
        ArrayList.h
        TailList.cpp
        TailList.h
        ui.cpp
        ui.h
)
