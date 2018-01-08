//
// Created by nbollom on 27/04/17.
//

#include "log.h"
#include <string>
#include <ctime>
#include <algorithm>

namespace NinjaFramework {
    namespace Log {

        std::ostream NULL_STREAM(nullptr);

        std::string LevelName(Level level) {
            if (level == Debug) {
                return "DEBUG";
            } else if (level == Info) {
                return "INFO";
            } else if (level == Warning) {
                return "WARNING";
            } else if (level == Error) {
                return "ERROR";
            } else {
                throw std::runtime_error("Invalid logging level");
            }
        }

        Level LevelFromName(std::string level_str) {
            std::string upper_str = level_str;
            std::transform(upper_str.begin(), upper_str.end(), upper_str.begin(),
                           std::ptr_fun<int, int>(std::toupper));
            if (upper_str == "DEBUG") {
                return Debug;
            } else if (upper_str == "INFO") {
                return Info;
            } else if (upper_str == "WARNING") {
                return Warning;
            } else if (upper_str == "ERROR") {
                return Error;
            } else {
                throw std::runtime_error("Invalid logging level");
            }
        }

        Logger::Logger(std::ostream &stream) : log_stream(stream.rdbuf()) {
            log_level = Warning;
        }

        Logger::~Logger() {
            if (output_buffer.is_open()) {
                output_buffer.close();
            }
        }

        void Logger::Flush() {
            log_stream.flush();
        }

        std::ostream *Logger::GetStream(Level level) {
            if (level >= log_level) {
                std::time_t t = std::time(nullptr);
                char date_string[100];
                if (std::strftime(date_string, sizeof(date_string), "%F %T", std::localtime(&t))) {
                    log_stream << date_string << " [" << LevelName(level) << "]: ";
                }
                return &log_stream;
            } else {
                return &NULL_STREAM;
            }
        }

        void Logger::SetLogLevel(Level level) {
            log_level = level;
        }

        Level Logger::LogLevel() {
            return log_level;
        }

        Logger *log_instance = nullptr;

        void Init(Level level, std::ostream &stream) {
            if (log_instance == nullptr) {
                log_instance = new Logger(stream);
            }
            log_instance->SetLogLevel(level);
        }

        void SetLevel(Level level) {
            if (log_instance == nullptr) {
                throw std::runtime_error("Log not initialised");
            }
            log_instance->SetLogLevel(level);
        }

        void Flush() {
            if (log_instance == nullptr) {
                throw std::runtime_error("Log not initialised");
            }
            log_instance->Flush();
        }

        void Close() {
            if (log_instance != nullptr) {
                log_instance->Flush();
                delete log_instance;
                log_instance = nullptr;
            }
        }

        std::ostream *GetStream(Level level) {
            if (log_instance == nullptr) {
                return &NULL_STREAM;
            }
            return log_instance->GetStream(level);
        }

    }
}
