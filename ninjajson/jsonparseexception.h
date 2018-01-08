//
// Created by nbollom on 22/06/17.
//

#ifndef NINJAJSON_JSONPARSEEXCEPTION_H
#define NINJAJSON_JSONPARSEEXCEPTION_H

#include <stdexcept>

namespace NinjaFramework {
    namespace JSON {

        class JSONParseException : public std::exception {

        private:
            const std::string _message;
            const int _line;
            const int _character;

        public:
            JSONParseException(const std::string &message, JSONParseStream *source) : _message(message),
                                                                                      _line(source->line()),
                                                                                      _character(
                                                                                              source->character()) {
            }

            JSONParseException(const char *message, JSONParseStream *source) : _message(message),
                                                                               _line(source->line()),
                                                                               _character(source->character()) {
            }

            const char *what() const noexcept override {
                return _message.c_str();
            };

            const int line() {
                return _line;
            }

            const int character() {
                return _character;
            }

        };

    }
}

#endif //NINJAJSON_JSONPARSEEXCEPTION_H
