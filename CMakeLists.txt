cmake_minimum_required(VERSION 3.29)

project(SolidEngine C CXX)

set(SOURCES
    src/main.cpp
    src/game.cpp
    src/scene.cpp
    src/renderer/renderer.cpp
    src/renderer/shader.cpp
    src/renderer/camera.cpp
    src/renderer/mesh.cpp
    #src/input.cpp
)

include_directories(src)
link_libraries(mingw32 SDL2main SDL2 glu32 opengl32 glew32)
add_executable(solidengine ${SOURCES})
