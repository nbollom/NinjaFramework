//
// Created by nbollom on 29/11/17.
//

#ifndef NINJAFRAMEWORK_PACKFILEENTRY_H
#define NINJAFRAMEWORK_PACKFILEENTRY_H

#include <string>
#include <iostream>
#include "enums.h"

namespace NinjaFramework {
    namespace Pack {

        class PackFileEntry {

        private:
            std::string _path;
            uint64_t _offset;
            uint64_t _size;
            uint64_t _compressed;
            uint64_t _modified;

        public:
            explicit PackFileEntry(std::string path, std::string relative_to);
            explicit PackFileEntry(std::string relative_path, std::istream source);

        };

    }
}

#endif //NINJAFRAMEWORK_PACKFILEENTRY_H
