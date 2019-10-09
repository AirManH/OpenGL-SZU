cmake_minimum_required(VERSION 3.0)

project(main)

if (WIN32)
    set(OpenGlLinkers -lglew32 -lglu32 -lfreeglut -lopengl32)
elseif (UNIX)
    set(OpenGlLinkers -lglut -lGLU -lGL -lGLEW)
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