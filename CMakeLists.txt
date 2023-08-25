cmake_minimum_required(VERSION 3.26)
project(tangl)

set(CMAKE_CXX_STANDARD 17)
set(OpenGlLinkers -lglut -lGLU -lGL) # setting all the Glut libraries as one variable.

add_executable(tangl main.cpp)

################################################

target_link_libraries(tangl ${OpenGlLinkers}) # linking opengl libraries to the project

#################################################
