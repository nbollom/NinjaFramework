cmake_minimum_required(VERSION 3.7)
project(file_test)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        catch.hpp
        main.cpp
        file.cpp)

add_executable(file_test ${SOURCE_FILES})
include_directories(file_test ${ninjalog_SOURCE_DIR})
target_link_libraries(file_test ninjafile)

add_test(NAME file
        COMMAND file_test -d y
        )
