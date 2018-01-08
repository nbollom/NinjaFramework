//
// Created by nbollom on 7/06/17.
//

#ifndef NINJAJSON_JSONVALUE_H
#define NINJAJSON_JSONVALUE_H

#include <string>
#include <stdexcept>
#include <memory>

namespace NinjaFramework {
    namespace JSON {

        class Array;

        class Object;

        class Value {

        protected:
            Value() = default;;

        public:
            virtual ~Value() = default;
            virtual std::shared_ptr<Value> Copy() = 0;
            virtual bool IsIterable() { return false; }
            virtual bool IsObject() { return false; }
            virtual bool IsArray() { return false; }
            virtual bool IsNull() { return false; }
            virtual bool IsString() { return false; }
            virtual bool IsNumber() { return false; }
            virtual bool IsBool() { return false; }
            virtual std::shared_ptr<Object> AsObject();
            virtual std::shared_ptr<Array> AsArray();
            virtual std::wstring StringValue() = 0;
            virtual double NumberValue() = 0;
            virtual bool BooleanValue() = 0;

            virtual std::wstring JSONString() = 0;
        };

    }
}

#endif //NINJAJSON_JSONVALUE_H
