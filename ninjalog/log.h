//
// Created by nbollom on 27/04/17.
//

#ifndef NINJAJSON_LOGGING_H
#define NINJAJSON_LOGGING_H

#include <ostream>
#include <fstream>
#include <iostream>

namespace NinjaFramework {
    namespace Log {

        typedef enum {
            Debug = 0,
            Info = 1,
            Warning = 2,
            Error = 3
        } Level;

        std::string LevelName(Level level);

        Level LevelFromName(std::string level_str);

        class Logger {
#pragma mark Private Variables
        private:
            Level log_level;
            std::filebuf output_buffer;
            std::ostream log_stream;

#pragma mark Private Methods
        private:

#pragma mark Constructor/Destructor
        public:
            explicit Logger(std::ostream &stream);

            virtual ~Logger();


#pragma mark Public Methods
        public:
            void Flush();

#pragma mark Accessors

            std::ostream *GetStream(Level level);

            Level LogLevel();

            void SetLogLevel(Level level);
        };

        void Init(Level level = Log::Warning, std::ostream &stream = std::cerr);

        void SetLevel(Level level);

        void Flush();

        void Close();

        std::ostream *GetStream(Level level);
    }
}

#define log_debug *NinjaFramework::Log::GetStream(NinjaFramework::Log::Debug)
#define log_info *NinjaFramework::Log::GetStream(NinjaFramework::Log::Info)
#define log_warning *NinjaFramework::Log::GetStream(NinjaFramework::Log::Warning)
#define log_error *NinjaFramework::Log::GetStream(NinjaFramework::Log::Error)

#endif //NINJAJSON_LOGGING_H
