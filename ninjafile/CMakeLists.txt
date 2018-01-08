cmake_minimum_required(VERSION 3.8)
project(ninjafile)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        file.h
        )

set(SOURCE_FILES
        file.cpp
        )

add_library(ninjafile SHARED ${HEADER_FILES} ${SOURCE_FILES})
set_target_properties(ninjafile PROPERTIES
        VERSION 1.0
        SOVERSION 1)

option(FILE_BUILD_TESTS "Build and run the tests for the file loader library" OFF)

if(FILE_BUILD_TESTS OR BUILD_ALL_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

install(FILES ${HEADER_FILES} DESTINATION include/ninjaframework/ninjafile)
install(TARGETS ninjafile
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
