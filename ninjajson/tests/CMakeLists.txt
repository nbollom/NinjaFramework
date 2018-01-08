cmake_minimum_required(VERSION 3.7)
project(json_test)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        catch.hpp
        main.cpp
        json.cpp)

add_executable(json_test ${SOURCE_FILES})
include_directories(json_test ${ninjajson_SOURCE_DIR})
target_link_libraries(json_test ninjajson ninjalog)

add_test(NAME json
        COMMAND json_test -d y)
