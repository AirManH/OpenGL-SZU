cmake_minimum_required(VERSION 3.0)


project(OPENGL_SZU)


find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)


add_executable(main)

target_sources(main
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Common/InitShader.cpp)

target_include_directories(main
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(main
  PRIVATE
    OpenGL::OpenGL
    GLUT::GLUT
    GLEW::GLEW)


# copy shader

add_custom_command(TARGET main POST_BUILD
  COMMAND
    ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_SOURCE_DIR}/src/fshader.glsl $<TARGET_FILE_DIR:main>
  COMMAND
    ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vshader.glsl $<TARGET_FILE_DIR:main>)
