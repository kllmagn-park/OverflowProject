cmake_minimum_required(VERSION 3.20)
project(OverflowProject)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX STANDARD 14)

set(SOURCE_DIR src)
set(HEADERS_DIR include)

add_compile_options(-Wall -Wextra -pedantic)

if (CMAKE_BUILD_TYPE=Release)
    add_compile_options(-O3)
elseif(CMAKE_BUILD_TYPE=Debug)
    add_compile_options(-g)
endif()

if (COVERAGE)
    add_compile_options(--coverage)
    add_link_options(--coverage)
endif()

if (WPADDED)
    add_compile_options(-Wpadded)
endif()

if (TESTS OR SANITIZERS OR COVERAGE OR VALGRIND)
    find_package(GTest REQUIRED)
    enable_testing()
    set(BUILD_TESTS 1)
endif()

add_executable(main ${SOURCE_DIR}/main.cpp ${SOURCE_DIR}/home.cpp ${SOURCE_DIR}/settings.cpp)
if (CMAKE_BUILD_TYPE=Release)
    target_link_libraries(main wt wthttp)
elseif(CMAKE_BUILD_TYPE=Debug)
    target_link_libraries(main wtd wthttpd)
endif()
target_include_directories(main PUBLIC ${HEADERS_DIR})