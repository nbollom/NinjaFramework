//
// Created by Nathan Bollom on 16/06/2017.
//

#include "catch.hpp"
#include "log.h"
#include <iostream>
#include <sstream>

using namespace NinjaFramework;

template <typename T,unsigned S>
inline unsigned arraysize(const T (&v)[S]) { return S; }

const std::string debug_string = "This is a low level debug message";
const std::string info_string = "Here is some cool info for you";
const std::string warning_string = "Just a warning don't panic";
const std::string error_string = "Whoops, something has gone wrong";

TEST_CASE("Log should only output levels greater or equal to the current set level", "[LOG]") {
    std::stringstream log_stream;

    bool found_debug = false;
    bool found_info = false;
    bool found_warning = false;
    bool found_error = false;

    Log::Init(Log::Error, log_stream);

    SECTION("Error LogLevel") {
        log_debug << debug_string << std::endl;
        log_info << info_string << std::endl;
        log_warning << warning_string << std::endl;
        log_error << error_string << std::endl;
        Log::Flush();
        std::string line;
        while (std::getline(log_stream, line)) {
            found_debug = line.find(debug_string) != std::string::npos | found_debug;
            found_info = line.find(info_string) != std::string::npos | found_info;
            found_warning = line.find(warning_string) != std::string::npos | found_warning;
            found_error = line.find(error_string) != std::string::npos | found_error;
        }
        REQUIRE(!found_debug);
        REQUIRE(!found_info);
        REQUIRE(!found_warning);
        REQUIRE(found_error);
    }

    found_debug = found_info = found_warning = found_error = false;
    Log::SetLevel(Log::Warning);

    SECTION("Warning LogLevel") {
        log_debug << debug_string << std::endl;
        log_info << info_string << std::endl;
        log_warning << warning_string << std::endl;
        log_error << error_string << std::endl;
        Log::Flush();
        std::string line;
        while (std::getline(log_stream, line)) {
            found_debug = line.find(debug_string) != std::string::npos | found_debug;
            found_info = line.find(info_string) != std::string::npos | found_info;
            found_warning = line.find(warning_string) != std::string::npos | found_warning;
            found_error = line.find(error_string) != std::string::npos | found_error;
        }
        REQUIRE(!found_debug);
        REQUIRE(!found_info);
        REQUIRE(found_warning);
        REQUIRE(found_error);
    }

    found_debug = found_info = found_warning = found_error = false;
    Log::SetLevel(Log::Info);

    SECTION("Info LogLevel") {
        log_debug << debug_string << std::endl;
        log_info << info_string << std::endl;
        log_warning << warning_string << std::endl;
        log_error << error_string << std::endl;
        Log::Flush();
        std::string line;
        while (std::getline(log_stream, line)) {
            found_debug = line.find(debug_string) != std::string::npos | found_debug;
            found_info = line.find(info_string) != std::string::npos | found_info;
            found_warning = line.find(warning_string) != std::string::npos | found_warning;
            found_error = line.find(error_string) != std::string::npos | found_error;
        }
        REQUIRE(!found_debug);
        REQUIRE(found_info);
        REQUIRE(found_warning);
        REQUIRE(found_error);
    }

    found_debug = found_info = found_warning = found_error = false;
    Log::SetLevel(Log::Debug);

    SECTION("Debug LogLevel") {
        log_debug << debug_string << std::endl;
        log_info << info_string << std::endl;
        log_warning << warning_string << std::endl;
        log_error << error_string << std::endl;
        Log::Flush();
        std::string line;
        while (std::getline(log_stream, line)) {
            found_debug = line.find(debug_string) != std::string::npos | found_debug;
            found_info = line.find(info_string) != std::string::npos | found_info;
            found_warning = line.find(warning_string) != std::string::npos | found_warning;
            found_error = line.find(error_string) != std::string::npos | found_error;
        }
        REQUIRE(found_debug);
        REQUIRE(found_info);
        REQUIRE(found_warning);
        REQUIRE(found_error);
    }

    Log::Close();
}
