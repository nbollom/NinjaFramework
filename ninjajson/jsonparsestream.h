//
// Created by nbollom on 22/06/17.
//

#ifndef NINJAJSON_JSONPARSESTREAM_H
#define NINJAJSON_JSONPARSESTREAM_H

#include <istream>
#include <vector>

namespace NinjaFramework {
    namespace JSON {

        class JSONParseStream {

        private:
            std::wistream *_source;
            int _line;
            std::vector<int> _characters;

        public:
            explicit JSONParseStream(std::wistream *source);
            wchar_t get();
            void unget();
            bool eof() const;
            int line();
            int character();
        };

    }
}

#endif //NINJAJSON_JSONPARSESTREAM_H
