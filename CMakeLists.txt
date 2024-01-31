cmake_minimum_required(VERSION 3.10)
project(my_program)

find_package(glfw3 3.3 REQUIRED)
add_executable(my_program ex.cpp)
target_link_libraries(my_program glfw)
set_target_properties(my_program PROPERTIES RUNTIME_OUTPUT_DIRECTORY progr)

