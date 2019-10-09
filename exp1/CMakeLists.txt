cmake_minimum_required(VERSION 3.0)

project(main)

if (WIN32)
    set(OpenGlLinkers -lglew32 -lglu32 -lfreeglut -lopengl32)
elseif (UNIX)
    set(OpenGlLinkers -lglut -lGLU -lGL -lGLEW)
endif ()

ADD_LIBRARY(GfxModule ${CMAKE_SOURCE_DIR}/Common/InitShader.cpp)

target_link_libraries(GfxModule ${OpenGlLinkers})

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(main main.cpp)
target_link_libraries(main GfxModule)
