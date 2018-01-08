//
// Created by Nathan Bollom on 14/06/2017.
//

#ifndef NINJAJSON_JSONSTRING_H
#define NINJAJSON_JSONSTRING_H

#include "jsonvalue.h"

namespace NinjaFramework {
    namespace JSON {

        class String : public Value {

        private:
            std::wstring _value;

        public:
            String();
            explicit String(std::wstring &string);
            explicit String(std::shared_ptr<String> other);
            ~String() override;
            std::shared_ptr<Value> Copy() override;
            bool IsString() override;
            std::wstring StringValue() override;
            double NumberValue() override;
            bool BooleanValue() override;

            std::wstring JSONString() override;
        };

    }
}

#endif //NINJAJSON_JSONSTRING_H
