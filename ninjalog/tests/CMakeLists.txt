cmake_minimum_required(VERSION 3.7)
project(log_test)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        catch.hpp
        main.cpp
        log.cpp)

add_executable(log_test ${SOURCE_FILES})
include_directories(log_test ${ninjalog_SOURCE_DIR})
target_link_libraries(log_test ninjalog)

add_test(NAME log
        COMMAND log_test -d y
        )

