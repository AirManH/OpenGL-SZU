cmake_minimum_required(VERSION 3.0)

project(main)

if (WIN32)
    set(OpenGlLinkers -lglew32 -lglu32 -lfreeglut -lopengl32)
elseif (UNIX)
    find_library(glut_lib glut)
    find_library(GLU_lib GLU)
    find_library(GL_lib GL)
    find_library(GLEW_lib GLEW)
    set(OpenGlLinkers ${glut_lib} ${GLU_lib} ${GL_lib} ${GLEW_lib})
endif ()

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(main main.cpp ${CMAKE_SOURCE_DIR}/Common/InitShader.cpp)
target_link_libraries(main ${OpenGlLinkers})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD

        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/fshader.glsl $<TARGET_FILE_DIR:${PROJECT_NAME}>

        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/vshader.glsl $<TARGET_FILE_DIR:${PROJECT_NAME}>
        )