cmake_minimum_required(VERSION 3.9)
project(FinalProject)
include_directories(
        lib/glfw/include
        lib/glad/include
        lib/glm/)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/glfw)
add_subdirectory(lib/glm)

add_executable(FinalProject main.cpp glad.c stb_image.cpp shader.h shader.cpp)
target_link_libraries(FinalProject glfw)