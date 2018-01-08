//
// Created by Nathan Bollom on 7/06/2017.
//

#ifndef NINJAJSON_JSONITERABLE_H
#define NINJAJSON_JSONITERABLE_H

#include <vector>
#include <map>
#include <string>
#include "jsonvalue.h"

namespace NinjaFramework {
    namespace JSON {

        typedef std::vector<std::shared_ptr<Value>>::iterator value_iterator;
        typedef std::map<std::wstring, std::shared_ptr<Value>>::iterator object_iterator;

        class Iterable : public Value {

        protected:
            Iterable() = default;

        public:
            virtual uint64_t Length() = 0;
            bool IsIterable() override;
            virtual value_iterator values_begin() = 0;
            virtual value_iterator values_end() = 0;
            virtual object_iterator object_begin() = 0;
            virtual object_iterator object_end() = 0;

        };

    }
}

#endif //NINJAJSON_JSONITERABLE_H
