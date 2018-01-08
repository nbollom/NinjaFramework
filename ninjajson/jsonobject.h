//
// Created by Nathan Bollom on 7/06/2017.
//

#ifndef NINJAJSON_JSONOBJECT_H
#define NINJAJSON_JSONOBJECT_H

#include <map>
#include <string>
#include "jsoniterable.h"

namespace NinjaFramework {
    namespace JSON {

        class Object : public Iterable {

        private:
            std::map<std::wstring, std::shared_ptr<Value>> _map;

        public:
            Object();
            explicit Object(std::shared_ptr<Object> other);
            explicit Object(std::map<std::wstring, std::shared_ptr<Value>> &map);
            ~Object() override;
            std::shared_ptr<Value> Copy() override;
            bool HasKey(const std::wstring &key);
            uint64_t Length() override;
            std::shared_ptr<Object> AsObject() override;
            std::shared_ptr<Array> AsArray() override;
            std::shared_ptr<Value> operator[](const std::wstring &key);
            bool IsObject() override;
            std::wstring StringValue() override;
            double NumberValue() override;
            bool BooleanValue() override;
            value_iterator values_begin() override;
            value_iterator values_end() override;
            object_iterator object_begin() override;
            object_iterator object_end() override;
            object_iterator begin();
            object_iterator end();
            void Add(const std::wstring &key, std::shared_ptr<Value> &value);
            std::shared_ptr<Value> Get(const std::wstring &key);
            void Remove(const std::wstring &key);

            std::wstring JSONString() override;
        };

    }
}

#endif //NINJAJSON_JSONOBJECT_H
