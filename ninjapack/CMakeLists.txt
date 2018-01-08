cmake_minimum_required(VERSION 3.8)
project(ninjapack)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        pack.h
        enums.h packfileentry.h)

set(SOURCE_FILES
        filestructs.h
        pack.cpp
        packfileentry.cpp)

add_library(ninjapack SHARED ${HEADER_FILES} ${SOURCE_FILES})
set_target_properties(ninjapack PROPERTIES
        VERSION 1.0
        SOVERSION 1)

option(PACK_BUILD_TESTS "Build and run the tests for the pack file handler library" OFF)

if(PACK_BUILD_TESTS OR BUILD_ALL_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

install(FILES ${HEADER_FILES} DESTINATION include/ninjaframework/ninjapack)
install(TARGETS ninjapack
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
