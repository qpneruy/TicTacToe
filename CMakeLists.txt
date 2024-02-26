cmake_minimum_required(VERSION 3.27)
project(TicTacToev2)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(TicTacToev2
        src/main.cpp
        src/lib/drawScreen.cpp
        src/include/drawScreen.h
        src/lib/winLogic.cpp
        src/include/winLogic.h
        src/lib/mapping.cpp
        src/include/mapping.h
        src/lib/touchLogic.cpp
        src/include/touchLogic.h
        src/dataInput.cpp
        src/include/dataInput.h
        src/lib/archive.cpp
        src/include/archive.h
)
