#pragma once

#include <base.hpp>
#include <cstring>
#include <stdio.h>

namespace hny {
    class _str {
        public:

        char *c;

        // empty string
        _str() {
            this->c = new char[1];
            this->c[0] = '\0';
        };

        // C string -> Honey string
        _str(const char *c) {
            if (c == nullptr)
                rt::NullError.raise("C-capability <str> constructor got nullptr as parameter");
            size_t length = strlen(c);
            this->c = new char[length];
            strcpy(this->c, c);
        };

        // empty string with length C
        _str(uint c) {
            this->c = new char[c];
            this->c[c] = this->c[0] = '\0';
        };

        // Honey cast integer to string
        _str(_uint c) {
            
            if (!c.c) {
                this->c = new char[2];
                this->c[0] = '0';
                this->c[1] = '\0';
                return;
            }

            ushort power = 0;
            uint c2 = c.c;

            // firstly we need to find target string length
            while (c2) {
                power++;
                c2 /= 10;
            }

            c2 = c.c;

            // fine. now we can allocate needed memory
            this->c = new char[power+1];
            this->c[power] = '\0';

            /*
            // now we should fill in buffer with digits
            for (ushort i = 0; i < power; i++)
            {

                // write digit
                this->c[power - i - 1] = MIN(c2, 9) + '0';
                c2 /= 10;
            }
            */

           sprintf(this->c, "%d", c2);
        }

        // Honey string -> C string
        char *__to_c() {
            return this->c;
        };

        // get length of string
        _uint length() {
            return (uint)strlen(this->c);
        }

        // Honey string -> C boolean
        explicit operator bool() const {
            return strlen(this->c);
        };

        // string concatanating
        _str operator+(_str other) {
            NEW(_str,rv,(((this->length() + other.length())).c));
            strcpy(rv->c, this->c);
            strcpy((char *)((ulong)rv->c+strlen(this->c)), other.c);
            return *rv;
        };

        // invalid operator
        void operator-(_str other) {
            rt::TypeError.raise("invalid operator \"-\" for type <str>");
        };

        // string repeating
        _str operator*(auto other) {
            NEW(_str,rv,(this->length() * other));
            for (unsigned i = 0; i < other.__to_c(); i++)
                strcpy((char *)(_uint((uint)(ulong)rv->c)+this->length()*i).__to_c(), this->c);
            return *rv;
        };

        // invalid operator
        void operator/(any other) {
            rt::TypeError.raise("invalid operator \"/\" for type <str>");
        };

        // invalid operator
        void operator++() {
            rt::TypeError.raise("invalid operator \"++\" for type <str>");
        };

        // invalid operator
        void operator--() {
            rt::TypeError.raise("invalid operator \"--\" for type <str>");
        };

        // cut left
        _str operator<<(_uint other) {
            NEW(_str,rv,(this->length().c - other.c));
            
            for (uint i = other.c; i < this->length().c; i++) {
                rv->__setitem(i, this->c[i]);
            }

            return *rv;
        };

        // cut right
        _str operator>>(_uint other) {
            NEW(_str,rv,(other.c));
            
            for (uint i = 0; i < other.c; i++) {
                rv->__setitem(i, this->c[i]);
            }

            return *rv;
        };

        // invalid operator
        void operator^(any other) {
            rt::TypeError.raise("invalid operator \"^\" for type <str>");
        };

        // is empty?
        _bool operator!() {
            return !strlen(this->c);
        };

        // reverse string
        _str operator~() {
            NEW(_str,rv,(this->length().c));

            for (uint i; i < this->length().c; i++)
                rv->c[i] = this->c[this->length().c - i - 1];

            return *rv;
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
            return (bool)this && (bool)other;
        };

        _bool operator||(_str other) {
            return (bool)this || (bool)other;
        };

        // invalid operator
        void operator&(_str other) {
            rt::TypeError.raise("invalid operator \"&\" for type <str>");
        };

        // invalid operator
        void operator|(_str other) {
            rt::TypeError.raise("invalid operator \"|\" for type <str>");
        };

        // get symbol
        _str __getitem(_uint index) {
            NEW(_str,rv,(_uint(1U)));
            rv->c[0] = this->c[index.__to_c()];
            return *rv;
        };

        // set symbol. yes, in honey strings are modifiable!)
        void __setitem(_uint index, _str value) {
            if (strlen(value.c) != 1)
                rt::_error("ValueError").raise("value for str setitem must be 1-length");
            this->c[index.__to_c()+1] = value.c[0];
        }
    };
};
