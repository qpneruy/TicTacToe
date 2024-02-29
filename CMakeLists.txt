cmake_minimum_required(VERSION 3.27)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(TicTacToe
        src/main.cpp
        src/lib/drawScreen.cpp
        src/include/drawScreen.h
        src/lib/winLogic.cpp
        src/include/winLogic.h
        src/lib/mapping.cpp
        src/include/mapping.h
        src/lib/touchLogic.cpp
        src/include/touchLogic.h
        src/lib/dataInput.cpp
        src/include/dataInput.h
        src/lib/archive.cpp
        src/include/archive.h
        src/lib/loadGame.cpp
        src/include/loadGame.h
        src/lib/drawScreen/inBangXepHang.cpp
        src/include/drawScreen/inBangXepHang.h
)
