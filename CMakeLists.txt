cmake_minimum_required(VERSION 3.9)
project(FinalProject)
include_directories(
        include
        lib/glfw/include
        lib/glad/include
        lib/glm/)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/glfw)
add_subdirectory(lib/glm)

add_executable(FinalProject main.cpp glad.c stb_image.cpp include/shader.h shader.cpp include/Planet.h Planet.cpp include/Simulator.h Simulator.cpp include/Camera.h Camera.cpp)
target_link_libraries(FinalProject glfw)