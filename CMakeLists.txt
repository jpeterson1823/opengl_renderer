cmake_minimum_required(VERSION 3.26)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

project(snake_gl)

# add files
include_directories(./include)
add_executable(snake_gl
    src/main.cpp
    src/glad.c

    src/game/GameObject.cpp
    src/game/World.cpp

    src/render/Camera.cpp
    src/render/Renderer.cpp
    src/render/ResourceManager.cpp
    src/render/Shader.cpp
    src/render/Texture2D.cpp

    src/render/shapes/Line.cpp
)

# GLFW Setup
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(./libs/glfw-3.3.8)
target_link_libraries(snake_gl glfw)

# OpenGL Setup
find_package(OpenGL REQUIRED)
target_link_libraries(snake_gl OpenGL::GL)

# GLM Setup
set(glm_DIR ./libs/glm/cmake/glm) # if necessary
find_package(glm REQUIRED)
target_link_libraries(snake_gl glm::glm)
