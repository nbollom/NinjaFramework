//
// Created by Nathan Bollom on 7/06/2017.
//

#include "jsonarray.h"
#include "jsonobject.h"
#include "config.h"

namespace NinjaFramework {
    namespace JSON {

        Array::Array(std::shared_ptr<Array> other) {
            for (auto &value : *other) {
                _values.push_back(value->Copy());
            }
        }

        Array::Array(std::vector<std::shared_ptr<Value>> &values) {
            _values = values;
        }

        Array::~Array() {
            _values.clear();
        }

        std::shared_ptr<Value> Array::Copy() {
            return std::make_shared<Array>(_values);
        }

        bool Array::HasIndex(uint64_t index) {
            return index < _values.size();
        }

        uint64_t Array::Length() {
            return _values.size();
        }

        std::shared_ptr<Array> Array::AsArray() {
            return std::make_shared<Array>(_values);
        }

        std::shared_ptr<Object> Array::AsObject() {
            std::map<std::wstring, std::shared_ptr<Value>> map;
            int index = 0;
            for (auto &value : _values) {
                map[std::to_wstring(index)] = value;
                index++;
            }
            return std::make_shared<Object>(map);
        }

        std::shared_ptr<Value> Array::operator[](uint64_t index) {
            return Get(index);
        }

        bool Array::IsArray() {
            return true;
        }

        std::wstring Array::StringValue() {
            return L"[Array]";
        }

        double Array::NumberValue() {
            return 1;
        }

        bool Array::BooleanValue() {
            return true;
        }

        value_iterator Array::values_begin() {
            return this->AsArray()->begin();
        }

        value_iterator Array::values_end() {
            return this->AsArray()->end();
        }

        object_iterator Array::object_begin() {
            return this->AsObject()->begin();
        }

        object_iterator Array::object_end() {
            return this->AsObject()->end();
        }

        value_iterator Array::begin() {
            return _values.begin();
        }

        value_iterator Array::end() {
            return _values.end();
        }

        void Array::PushFront(std::shared_ptr<Value> value) {
            _values.insert(_values.begin(), value);
        }

        void Array::PushBack(std::shared_ptr<Value> value) {
            _values.push_back(value);
        }

        std::shared_ptr<Value> Array::Get(uint64_t index) {
            return _values[index];
        }

        std::shared_ptr<Value> Array::PopFront() {
            std::shared_ptr<Value> value = _values.front();
            _values.erase(_values.begin());
            return value;
        }

        std::shared_ptr<Value> Array::PopBack() {
            std::shared_ptr<Value> value = _values.back();
            _values.pop_back();
            return value;
        }
        
        std::wstring Array::JSONString() {
            std::wstring string = L"[";
            bool first = true;
            for (auto &value: _values) {
                if (!first) {
                    string += L", ";
                }
                string += value->JSONString();
                first = false;
            }
            string += L"]";
            return string;
        }

    }
}
