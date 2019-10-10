cmake_minimum_required(VERSION 3.0)

project(main)

# find lib of opengl, glew, freeglut

if (WIN32)
    find_library(glu32_lib glu32)
    find_library(opengl32_lib opengl32)
    find_library(glew32_lib glew32
            PATHS ${CMAKE_SOURCE_DIR}/glew-2.1.0/lib/Release/x64)
    find_library(freeglut_lib freeglut
            PATHS ${CMAKE_SOURCE_DIR}/freeglut-3.0.0-MinGW/lib/x64)
    set(OpenGlLinkers ${glew32_lib} ${glu32_lib} ${freeglut_lib} ${opengl32_lib})
elseif (UNIX)
    find_library(glut_lib glut)
    find_library(GLU_lib GLU)
    find_library(GL_lib GL)
    find_library(GLEW_lib GLEW)
    set(OpenGlLinkers ${glut_lib} ${GLU_lib} ${GL_lib} ${GLEW_lib})
endif ()

# include

if (WIN32)
    include_directories(${CMAKE_SOURCE_DIR}/glew-2.1.0/include/)
    include_directories(${CMAKE_SOURCE_DIR}/freeglut-3.0.0-MinGW/include/)
endif ()

include_directories(${CMAKE_SOURCE_DIR}/include)

# build

add_executable(main main.cpp ${CMAKE_SOURCE_DIR}/Common/InitShader.cpp)
target_link_libraries(main ${OpenGlLinkers})

# copy dll for windows

if (WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD

            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_SOURCE_DIR}/freeglut-3.0.0-MinGW/bin/x64/freeglut.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>

            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_SOURCE_DIR}/glew-2.1.0/bin/Release/x64/glew32.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
            )
endif ()

# copy shader

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD

        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/fshader.glsl $<TARGET_FILE_DIR:${PROJECT_NAME}>

        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/vshader.glsl $<TARGET_FILE_DIR:${PROJECT_NAME}>
        )