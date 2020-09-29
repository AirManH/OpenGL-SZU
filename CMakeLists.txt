cmake_minimum_required(VERSION 3.16)


project(OPENGL_SZU)


add_executable(main)

# add source files
target_sources(main
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Common/InitShader.cpp)

# header files
target_include_directories(main
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

# link libraries
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

target_link_libraries(main
  PRIVATE
    OpenGL::OpenGL
    GLUT::GLUT
    GLEW::GLEW)

# reset output directory for target
set_target_properties(main
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# copy resources
file(GLOB OPENGL_SZU_RESOURCES
  CONFIGURE_DEPENDS
  "resource/*")

foreach(OPENGL_SZU_RESOURCE_FILE IN LISTS OPENGL_SZU_RESOURCES)
  add_custom_command(TARGET main PRE_BUILD
    COMMAND
      ${CMAKE_COMMAND} -E copy_if_different
      ${OPENGL_SZU_RESOURCE_FILE} $<TARGET_FILE_DIR:main>
      COMMENT "Copying resource file: ${OPENGL_SZU_RESOURCE_FILE}")
endforeach()
