cmake_minimum_required(VERSION 3.16)
project(Pendulum2D)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib REQUIRED)

add_executable(Pendulum2D
    main.cpp
    Components.cpp
)

target_link_libraries(Pendulum2D raylib)
