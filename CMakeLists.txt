cmake_minimum_required(VERSION 3.26)
project(Space_Shooter)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics audio)

add_executable(Space_Shooter main.cpp
        Obstacles.cpp
        Obstacles.h
        Player.cpp
        Player.h
        Score.cpp
        Score.h
        GameOverScreen.cpp
        GameOverScreen.h)

target_link_libraries(Space_Shooter sfml-graphics sfml-audio)
