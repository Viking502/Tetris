cmake_minimum_required(VERSION 3.13)
project(Tetris2)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Tetris2
        include/Blocks_system.h
        include/Game.h
        include/I_polyomino.h
        include/J_polyomino.h
        include/L_polyomino.h
        include/O_polyomino.h
        include/S_polyomino.h
        include/Structures.h
        include/T_polyomino.h
        include/Tetrimino.h
        include/Z_polyomino.h
        src/Blocks_system.cpp
        src/Game.cpp
        src/I_polyomino.cpp
        src/J_polyomino.cpp
        src/L_polyomino.cpp
        src/O_polyomino.cpp
        src/S_polyomino.cpp
        src/T_polyomino.cpp
        src/Tetrimino.cpp
        src/Z_polyomino.cpp
        main.cpp)

target_link_libraries(${PROJECT_NAME} -lsfml-graphics -lsfml-window -lsfml-system)