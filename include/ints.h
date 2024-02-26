#pragma once

#include <base.h>
#include <stdint.h>

namespace hny {
    template <typename T>
    class __int {
        public:

        T c;

        __int() {
            this->c = 0;
        };

        __int(T c) {
            this->c = c;
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
    typedef __int<u_char> _u8;
    typedef __int<ushort> _u16;
    typedef __int<ulong> _u32;
    typedef __int<uint64_t> _u64;

    typedef __int<int> _int;
    typedef __int<char> _i8;
    typedef __int<short> _i16;
    typedef __int<long> _i32;
    typedef __int<long long> _i64;
};
