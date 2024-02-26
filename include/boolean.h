#pragma once

#include <base.h>

namespace hny {
    class _bool {
        public:

        bool c;

        _bool() {
            this->c = false;
        };

        _bool(int c) {
            this->c = c ? true : false;
        };

        _bool(bool c) {
            this->c = c;
        };

        bool __to_c() {
            return this->c;
        };

        explicit operator bool() const {
            return this->c;
        };

        _bool operator+(_bool other) {
            return this->c || other.c;
        };

        void operator-(_bool other) {
            rt::TypeError.raise("invalid operator \"-\" for type <bool>");
        };

        _bool operator*(_bool other) {
            return this->c && other.c;
        };

        void operator/(_bool other) {
            rt::TypeError.raise("invalid operator \"/\" for type <bool>");
        };

        void operator++() {
            rt::TypeError.raise("invalid operator \"++\" for type <bool>");
        };

        void operator<<(any other) {
            rt::TypeError.raise("invalid operator \"<<\" for type <bool>");
        };

        void operator>>(any other) {
            rt::TypeError.raise("invalid operator \">>\" for type <bool>");
        };

        _bool operator^(_bool other) {
            return this->c ^ other.c;
        };

        _bool operator!() {
            _bool *rv = new _bool(!this->c);
            return *rv;
        };

        _bool operator~() {
            return !*this;
        };

        _bool operator==(_bool other) {
            return !(this->c ^ other.c);
        };

        _bool operator!=(_bool other) {
            return this->c ^ other.c;
        };

        _bool operator>(_bool other) {
            return this->c && !other.c;
        };

        _bool operator<(_bool other) {
            return !this->c && other.c;
        };

        _bool operator<=(_bool other) {
            return this->c == other.c || this->c < other.c;
        };

        _bool operator>=(_bool other) {
            return this->c == other.c || this->c > other.c;
        };

        _bool operator&&(_bool other) {
            return this->c && other.c;
        };

        _bool operator||(_bool other) {
            return this->c || other.c;
        };

        _bool operator&(_bool other) {
            return this->c * other.c;
        };

        _bool operator|(_bool other) {
            return this->c + other.c;
        };
    };
};
