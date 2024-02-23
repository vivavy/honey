#pragma once

#include <base.hpp>
#include <cstdint>

namespace hny {
    template <typename T>
    class __int : _base {
        T c;

        public:

        __int() {
            this->c = 0;
        };

        __int(T c) {
            this->c = c ? -1 : 0;
        };

        __int(bool c) {
            this->c = c ? 1 : 0;
        };

        bool __to_c() {
            return this->c;
        };

        explicit operator bool() const {
            return !!this->c;
        };

        __int operator+(__int other) {
            __int *rv = new __int(this->c + other.c);
            return *rv;
        };

        __int operator-(__int other) {
            __int *rv = new __int(this->c - other.c);
            return *rv;
        };

        __int operator*(__int other) {
            __int *rv = new __int(this->c * other.c);
            return *rv;
        };

        __int operator/(__int other) {
            __int *rv = new __int(this->c / other.c);
            return *rv;
        };

        __int operator++() {
            __int *rv = new __int(this->c++);
            return *rv;
        };

        __int operator--() {
            __int *rv = new __int(this->c--);
            return *rv;
        };

        __int operator<<(__int other) {
            __int *rv = new __int(this->c << other.c);
            return *rv;
        };

        __int operator>>(any other) {
            __int *rv = new __int(this->c >> other.c);
            return *rv;
        };

        __int operator^(__int other) {
            __int *rv = new __int(this->c ^ other.c);
            return *rv;
        };

        _bool operator!() {
            return !this->c;
        };

        __int operator~() {
            __int *rv = new __int(~this->c);
            return *rv;
        };

        _bool operator==(__int other) {
            return this->c == other.c;
        };

        _bool operator!=(__int other) {
            return this->c != other.c;
        };

        _bool operator>(__int other) {
            return this->c > other.c;
        };

        _bool operator<(__int other) {
            return this->c < other.c;
        };

        _bool operator<=(__int other) {
            return this->c <= other.c;
        };

        _bool operator>=(__int other) {
            return this->c >= other.c;
        };

        _bool operator&&(__int other) {
            return this->c && other.c;
        };

        _bool operator||(__int other) {
            return this->c || other.c;
        };

        __int operator&(__int other) {
            return this->c & other.c;
        };

        __int operator|(__int other) {
            return this->c | other.c;
        };
    };

    typedef __int<uint> _uint;
    typedef __int<uint8_t> _u8;
    typedef __int<uint16_t> _u16;
    typedef __int<uint32_t> _u32;
    typedef __int<uint64_t> _u64;
    typedef __int<__uint128_t> _u128;

    typedef __int<int> _int;
    typedef __int<int8_t> _i8;
    typedef __int<int16_t> _i16;
    typedef __int<int32_t> _i32;
    typedef __int<int64_t> _i64;
    typedef __int<__int128_t> _i128;
};
