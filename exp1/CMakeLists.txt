cmake_minimum_required(VERSION 3.0)

project(main)

ADD_LIBRARY(GfxModule
    ${CMAKE_SOURCE_DIR}/common/InitShader.cpp
)

target_link_libraries(GfxModule -lglew32)
target_link_libraries(GfxModule -lglu32)
target_link_libraries(GfxModule -lfreeglut)
target_link_libraries(GfxModule -lopengl32)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(main main.cpp)
target_link_libraries(main GfxModule)