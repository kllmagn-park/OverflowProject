add_executable(test_frontend src/test.cpp)
target_include_directories(test_frontend PUBLIC include)
target_link_libraries(test_frontend wttest Front GTest::Main)
add_test(NAME test_frontend COMMAND test_frontend)