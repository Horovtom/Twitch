cmake_minimum_required(VERSION 3.9)
project(twitch)

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_NAME
        "twitch"
        )

set(SOURCE_FILES twitch.cpp engine/Engine.cpp engine/Engine.h engine/graphics/Texture.cpp engine/graphics/Texture.h engine/graphics/Sprite.cpp engine/graphics/Sprite.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(glfw3 REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(twitch ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} glfw SOIL)

#Copy resources folder to compilation folder
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})