#pragma once

#include <base.hpp>
#include <string.h>

namespace hny {
    class _str : _base {
        char *c;

        public:

        _str() {
            this->c = nullptr;
        };

        _str(const char *c) {
            if (c == nullptr)
                rt::NullError.raise("<str> got nullptr in constructor");
            size_t length = strlen(c);
            this->c = new char[length];
            strcpy(this->c, c);
        };

        _str(_uint c) {
            this->c = new char[c.__to_c()];
        }

        const char *__to_c() {
            return this->c;
        };

        _uint length() {
            return (unsigned int)strlen(this->c);
        }

        explicit operator bool() const {
            return strlen(this->c);
        };

        _str operator+(_str other) {
            _str *rv = new _str(this->length() + other.length());
            strcpy(rv->c, this->c);
            strcpy((char *)((ulong)rv->c+strlen(this->c)), other.c);
            return *rv;
        };

        void operator-(_str other) {
            rt::TypeError.raise("invalid operator \"-\" for type <str>");
        };

        _str operator*(_uint other) {
            _str *rv = new _str(this->length() * other);
            for (unsigned i = 0; i < other.__to_c(); i++)
                strcpy((char *)(_uint((uint)(ulong)rv->c)+this->length()*i).__to_c(), this->c);
            return *rv;
        };

        void operator/(any other) {
            rt::TypeError.raise("invalid operator \"/\" for type <str>");
        };

        void operator++() {
            rt::TypeError.raise("invalid operator \"++\" for type <str>");
        };

        void operator--() {
            rt::TypeError.raise("invalid operator \"--\" for type <str>");
        };

        void operator<<(any other) {
            rt::TypeError.raise("invalid operator \"<<\" for type <str>");
        };

        void operator>>(any other) {
            rt::TypeError.raise("invalid operator \">>\" for type <str>");
        };

        void operator^(any other) {
            rt::TypeError.raise("invalid operator \"^\" for type <str>");
        };

        _bool operator!() {
            return !strlen(this->c);
        };

        void operator~() {
            rt::TypeError.raise("invalid operator \"~\" for type <str>");
        };

        _bool operator==(_str other) {
            return !strcmp(this->c, other.c);
        };

        _bool operator!=(_str other) {
            return !(*this == other);
        };

        _bool operator>(_str other) {
            return strlen(this->c) > strlen(other.c);
        };

        _bool operator<(_str other) {
            return strlen(this->c) < strlen(other.c);
        };

        _bool operator<=(_str other) {
            return *this == other || *this < other;
        };

        _bool operator>=(_str other) {
            return *this == other || *this > other;
        };

        _bool operator&&(_str other) {
            return *this && other;
        };

        _bool operator||(_str other) {
            return *this || other;
        };

        void operator&(_str other) {
            rt::TypeError.raise("invalid operator \"&\" for type <str>");
        };

        void operator|(_str other) {
            rt::TypeError.raise("invalid operator \"|\" for type <str>");
        };
    };
};
