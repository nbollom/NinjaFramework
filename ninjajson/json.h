//
// Created by nbollom on 7/06/17.
//

#ifndef NINJAJSON_JSON_H
#define NINJAJSON_JSON_H

#include <istream>
#include "jsonvalue.h"
#include "jsoniterable.h"
#include "jsonarray.h"
#include "jsonobject.h"
#include "jsonnull.h"
#include "jsonstring.h"
#include "jsonboolean.h"
#include "jsonnumber.h"
#include "jsonparsestream.h"

namespace NinjaFramework {
    namespace JSON {

        class Document {

        private:
            std::shared_ptr<Iterable> _root;

            static std::shared_ptr<Document> ParseDocument(JSONParseStream *source);
            static std::shared_ptr<Object> ParseObject(JSONParseStream *source);
            static std::shared_ptr<Array> ParseArray(JSONParseStream *source);
            static std::shared_ptr<Value> ParseValue(JSONParseStream *source);
            static std::shared_ptr<String> ParseString(JSONParseStream *source);
            static std::shared_ptr<Number> ParseNumber(JSONParseStream *source);
            static std::shared_ptr<Boolean> ParseBoolean(JSONParseStream *source);
            static std::shared_ptr<Null> ParseNull(JSONParseStream *source);

        public:
            Document();
            explicit Document(std::shared_ptr<Iterable> &root);
            explicit Document(std::shared_ptr<Document> &other);
            virtual ~Document();
            std::shared_ptr<Iterable> GetRoot();
            void SetRoot(std::shared_ptr<Iterable> &root);
            static std::shared_ptr<Document> Parse(std::wstring &string);
            static std::shared_ptr<Document> Parse(std::wistream &stream);
            void Write(std::wstring &string);
            void Write(std::wostream &stream);
        };

    }
}

#endif //NINJAJSON_JSON_H
