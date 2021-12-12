project(Frontend)
cmake_minimum_required(VERSION 3.16)

add_subdirectory(lib/Front)

add_executable(main src/main.cpp)
target_link_libraries(main Front)