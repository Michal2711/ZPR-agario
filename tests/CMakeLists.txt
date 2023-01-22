cmake_minimum_required(VERSION 3.12) # version can be different

project(my_cpp_project) #name of your project
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ".")

add_subdirectory(googletest) # add googletest subdirectory


include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>
include_directories(${PROJECT_SOURCE_DIR}/../include)

# add_executable(mytests ${PROJECT_SOURCE_DIR}/../src/*.cpp )
add_executable(mytests mytests.cpp) # add this executable

target_link_libraries(mytests PRIVATE gtest) # link google test to this executable