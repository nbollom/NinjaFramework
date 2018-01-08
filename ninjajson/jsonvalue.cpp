//
// Created by nbollom on 16/11/17.
//

#include "jsonvalue.h"
#include "config.h"

namespace NinjaFramework {
    namespace JSON {

        std::shared_ptr<Object> Value::AsObject() {
            RUNTIME_ERROR("Invalid type cast");
        }

        std::shared_ptr<Array> Value::AsArray() {
            RUNTIME_ERROR("Invalid type cast");
        }

    }
}