//
// Created by nbollom on 14/06/17.
//

#ifndef NINJAJSON_JSONNUMBER_H
#define NINJAJSON_JSONNUMBER_H

#include "jsonvalue.h"

namespace NinjaFramework {
    namespace JSON {

        class Number : public Value {

        private:
            double _value;

        public:
            Number();
            explicit Number(double number);
            explicit Number(std::shared_ptr<Number> other);
            ~Number() override;
            std::shared_ptr<Value> Copy() override;
            bool IsNumber() override;
            std::wstring StringValue() override;
            double NumberValue() override;
            bool BooleanValue() override;

            std::wstring JSONString() override;
        };

    }
}

#endif //NINJAJSON_JSONNUMBER_H
