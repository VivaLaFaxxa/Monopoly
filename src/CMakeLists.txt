cmake_minimum_required(VERSION 3.0.0)

project(monopoly_p)

include_directories(${PROJECT_SOURCE_DIR})

add_library(my_lib
    board.h 
    board.cpp
    computer_player.h 
    computer_player.cpp 
    human_player.h 
    human_player.cpp 
    player.h
    player.cpp 
    square.h 
    square.cpp 

    )

add_executable(main 
    monopoly.cpp)

target_link_libraries(main my_lib)
