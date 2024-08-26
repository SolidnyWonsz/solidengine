cmake_minimum_required(VERSION 3.29)

project(SolidEngine)

set(SOURCES
    src/main.cpp
    src/game.cpp
    src/scene.cpp
    src/loaders/obj.cpp
    src/renderer/renderer.cpp
    src/renderer/shader.cpp
    src/renderer/mesh.cpp
    src/common/logging.cpp
    src/common/tokenizer.cpp
)

include_directories(src)
link_libraries(mingw32 SDL2main SDL2 glu32 opengl32 glew32)
add_executable(solidengine ${SOURCES})