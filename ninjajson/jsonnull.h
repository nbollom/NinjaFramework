//
// Created by Nathan Bollom on 14/06/2017.
//

#ifndef NINJAJSON_JSONNULL_H
#define NINJAJSON_JSONNULL_H

#include "jsonvalue.h"

namespace NinjaFramework {
    namespace JSON {

        class Null : public Value {

        private:
            Null();

        public:
            ~Null() override;

            std::shared_ptr<Value> Copy() override;
            static std::shared_ptr<Null> NullPtr();
            bool IsNull() override;
            std::wstring StringValue() override;
            double NumberValue() override;
            bool BooleanValue() override;
            
            std::wstring JSONString() override;
        };

    }
}

#endif //NINJAJSON_JSONNULL_H
