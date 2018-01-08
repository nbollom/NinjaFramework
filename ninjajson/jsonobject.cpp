//
// Created by Nathan Bollom on 7/06/2017.
//

#include "jsonobject.h"
#include "jsonarray.h"

namespace NinjaFramework {
    namespace JSON {

        Object::Object() = default;

        Object::Object(std::shared_ptr<Object> other) {
            for (auto &i : *other) {
                std::pair < std::wstring, std::shared_ptr < Value >> pair = i;
                _map[pair.first] = pair.second->Copy();
            }
        }

        Object::Object(std::map<std::wstring, std::shared_ptr<Value>> &map) : _map(map) {
        }

        Object::~Object() {
            _map.clear();
        }

        std::shared_ptr<Value> Object::Copy() {
            return std::make_shared<Object>(_map);
        }

        bool Object::HasKey(const std::wstring &key) {
            return _map[key] != nullptr;
        }

        uint64_t Object::Length() {
            return _map.size();
        }

        std::shared_ptr<Object> Object::AsObject() {
            return std::make_shared<Object>(_map);
        }

        std::shared_ptr<Array> Object::AsArray() {
            std::vector<std::shared_ptr<Value>> values;
            for (auto &item: _map) {
                values.push_back(item.second);
            }
            return std::make_shared<Array>(values);
        }

        std::shared_ptr<Value> Object::operator[](const std::wstring &key) {
            return Get(key);
        }

        bool Object::IsObject() {
            return true;
        }

        std::wstring Object::StringValue() {
            return L"[Object]";
        }

        double Object::NumberValue() {
            return 1;
        }

        bool Object::BooleanValue() {
            return true;
        }

        value_iterator Object::values_begin() {
            return this->AsArray()->begin();
        }

        value_iterator Object::values_end() {
            return this->AsArray()->end();
        }

        object_iterator Object::object_begin() {
            return this->AsObject()->begin();
        }

        object_iterator Object::object_end() {
            return this->AsObject()->end();
        }

        object_iterator Object::begin() {
            return _map.begin();
        }

        object_iterator Object::end() {
            return _map.end();
        }

        void Object::Add(const std::wstring &key, std::shared_ptr<Value> &value) {
            _map[key] = value;
        }

        std::shared_ptr<Value> Object::Get(const std::wstring &key) {
            return _map[key];
        }

        void Object::Remove(const std::wstring &key) {
            std::shared_ptr < Value > value = _map[key];
            if (value != nullptr) {
                _map.erase(key);
            }
        }

        std::wstring Object::JSONString() {
            std::wstring string = L"{";
            bool first = true;
            for (auto &kvp: _map) {
                if (!first) {
                    string += L", ";
                }
                string += kvp.first + L": " + kvp.second->JSONString();
                first = false;
            }
            string += L"}";
            return string;
        }

    }
}
