#pragma once

#include <base.hpp>

namespace hny {
    class _bool : _base {
        uint8_t c;

        public:

        _bool() {
            this->c = 0;
        };

        _bool(int c) {
            this->c = c ? -1 : 0;
        };

        _bool(bool c) {
            this->c = c ? -1 : 0;
        };

        bool __to_c() {
            return !!this->c;
        };

        explicit operator bool() const {
            return !!this->c;
        };

        _bool operator+(_bool other) {
            return *this || other;
        };

        void operator-(_bool other) {
            rt::TypeError.raise("invalid operator \"-\" for type <bool>");
        };

        _bool operator*(_bool other) {
            return *this && other;
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
            _bool *rv = new _bool(this->c ? 0 : -1);
            return *rv;
        };

        _bool operator~() {
            return !*this;
        };

        _bool operator==(_bool other) {
            return !(*this ^ other);
        };

        _bool operator!=(_bool other) {
            return *this ^ other;
        };

        _bool operator>(_bool other) {
            return *this && !other;
        };

        _bool operator<(_bool other) {
            return !*this && other;
        };

        _bool operator<=(_bool other) {
            return *this == other || *this < other;
        };

        _bool operator>=(_bool other) {
            return *this == other || *this > other;
        };

        _bool operator&&(_bool other) {
            return *this && other;
        };

        _bool operator||(_bool other) {
            return *this || other;
        };

        _bool operator&(_bool other) {
            return *this * other;
        };

        _bool operator|(_bool other) {
            return *this + other;
        };
    };
};
