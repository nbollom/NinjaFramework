//
// Created by Nathan Bollom on 7/06/2017.
//

#ifndef NINJAJSON_JSONARRAY_H
#define NINJAJSON_JSONARRAY_H

#include <vector>
#include "jsoniterable.h"

namespace NinjaFramework {
    namespace JSON {

        class Array : public Iterable {

        private:
            std::vector<std::shared_ptr<Value>> _values;

        public:
            Array() = default;
            explicit Array(std::shared_ptr<Array> other);
            explicit Array(std::vector<std::shared_ptr<Value>> &values);
            ~Array() override;
            std::shared_ptr<Value> Copy() override;
            bool HasIndex(uint64_t index);
            uint64_t Length() override;
            std::shared_ptr<Array> AsArray() override;
            std::shared_ptr<Object> AsObject() override;
            std::shared_ptr<Value> operator[](uint64_t index);
            bool IsArray() override;
            std::wstring StringValue() override;
            double NumberValue() override;
            bool BooleanValue() override;
            value_iterator values_begin() override;
            value_iterator values_end() override;
            object_iterator object_begin() override;
            object_iterator object_end() override;
            value_iterator begin();
            value_iterator end();
            void PushFront(std::shared_ptr<Value> value);
            void PushBack(std::shared_ptr<Value> value);
            std::shared_ptr<Value> Get(uint64_t index);
            std::shared_ptr<Value> PopFront();
            std::shared_ptr<Value> PopBack();
            
            std::wstring JSONString() override;
        };

    }
}

#endif //NINJAJSON_JSONARRAY_H
