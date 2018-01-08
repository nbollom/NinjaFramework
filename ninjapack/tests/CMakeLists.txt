cmake_minimum_required(VERSION 3.7)
project(pack_test)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        catch.hpp
        main.cpp
        pack.cpp)

add_executable(pack_test ${SOURCE_FILES})
include_directories(pack_test ${ninjalog_SOURCE_DIR})
target_link_libraries(pack_test ninjapack)

add_test(NAME pack
        COMMAND pack_test -d y
        )
