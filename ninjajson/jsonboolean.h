//
// Created by nbollom on 14/06/17.
//

#ifndef NINJAJSON_JSONBOOLEAN_H
#define NINJAJSON_JSONBOOLEAN_H

#include "jsonvalue.h"

namespace NinjaFramework {
    namespace JSON {

        class Boolean : public Value {

        private:
            bool _value;

            explicit Boolean(bool value);

        public:
            ~Boolean() override;

            std::shared_ptr<Value> Copy() override;
            static std::shared_ptr<Boolean> True();
            static std::shared_ptr<Boolean> False();
            bool IsBool() override;
            std::wstring StringValue() override;
            double NumberValue() override;
            bool BooleanValue() override;

            std::wstring JSONString() override;
        };

    }
}

#endif //NINJAJSON_JSONBOOLEAN_H
