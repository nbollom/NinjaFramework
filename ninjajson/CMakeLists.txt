cmake_minimum_required(VERSION 3.8)
project(ninjajson)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        json.h
        jsonparseexception.h
        jsonparsestream.h
        jsonvalue.h
        jsoniterable.h
        jsonboolean.h
        jsonnull.h
        jsonnumber.h
        jsonstring.h
        jsonarray.h
        jsonobject.h
        )

set(SOURCE_FILES
        json.cpp
        jsonparsestream.cpp
        jsonvalue.cpp
        jsoniterable.cpp
        jsonboolean.cpp
        jsonnull.cpp
        jsonnumber.cpp
        jsonstring.cpp
        jsonarray.cpp
        jsonobject.cpp
        )

configure_file(config.h.in config.h)

add_library(ninjajson SHARED ${HEADER_FILES} config.h ${SOURCE_FILES})
set_target_properties(ninjajson PROPERTIES
        VERSION 1.0
        SOVERSION 1)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

if (BUILD_LOG)
    target_link_libraries(ninjajson ninjalog)
endif ()

option(JSON_BUILD_TESTS "Build and run the tests for the JSON library" OFF)

if(JSON_BUILD_TESTS OR BUILD_ALL_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

install(FILES ${HEADER_FILES} DESTINATION include/ninjaframework/ninjajson)
install(TARGETS ninjajson
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
