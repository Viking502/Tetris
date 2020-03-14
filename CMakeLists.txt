cmake_minimum_required(VERSION 3.13)
project(Tetris2)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Tetris2
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