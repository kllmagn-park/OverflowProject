cmake_minimum_required(VERSION 3.20)
project(OverflowProject)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX STANDARD 14)

set(SOURCE_DIR src)
set(HEADERS_DIR include)

set(ALIAS "[Frontend]")

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

add_library(Front ${SOURCE_DIR}/server.cpp ${SOURCE_DIR}/settings.cpp)
target_include_directories(Front PUBLIC ${HEADERS_DIR})

target_link_libraries(Front)

message("${ALIAS} Использую WebToolkit [Release].")
target_link_libraries(Front wt wthttp)

#message("Использую компонент Selector.")
#target_include_directories(Front PUBLIC lib/Selector/include)

if (TESTS OR SANITIZERS OR COVERAGE OR VALGRIND)
    message("${ALIAS} Ищу пакет GTest...")
    find_package(GTest REQUIRED)
    enable_testing()
    set(BUILD_TESTS 1)
endif()

if(BUILD_TESTS)
    message("${ALIAS} Использую тесты.")
    add_subdirectory(tests)
endif()