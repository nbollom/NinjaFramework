//
// Created by nbollom on 20/11/17.
//

#ifndef NINJAFRAMEWORK_PACK_H
#define NINJAFRAMEWORK_PACK_H

#include <fstream>
#include "filestructs.h"

namespace NinjaFramework {
    namespace Pack {

        class PackFile {

        private:
            std::fstream _source_file;
            PackHeader _header;

        public:
            explicit PackFile(std::fstream source);



        };

    }
}

#endif //NINJAFRAMEWORK_PACK_H
