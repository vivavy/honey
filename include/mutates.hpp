#pragma once

#include <base.hpp>

namespace hny {
    template <typename T>
    class _list : _base {
        T *value;
        _list<T> *next;

        public:

        _list() {
            this->value = nullptr;
            this->next = nullptr;
        };

        void __to_c() {
            rt::_error("IntegrationError").raise("attempt to convert linked list to C type");
        };

        explicit operator bool() const {
            return !!this->length();
        };

        T __getitem(_uint index) {
            if (index)
                if (this->next != nullptr)
                    return this->next->__getitem(--index);
                else
                    rt::_error("IndexError").raise("list index out of range");
            return *this->value;
        }

        _uint length() {
            if (this->next == nullptr)
                if (this->value == nullptr)
                    return 0;
                else
                    return 1;
            else
                return 1 + this->next->length().__to_c();
        };

        void append(T value) {
            if (this->next == nullptr) {
                if (this->value == nullptr) {this->value = &value;return;}
                this->next = new _list();
                this->next->value = &value;
                return;}
            this->next->append(value);
        };

        _list operator+(_list other) {
            _list rv = this->copy();
            for (uint i = 0; i < other.length(); i++) {
                rv.append(other.__getitem(_uint(i)));
            }
            return rv;
        };

        _list operator-(_list other) {
            _list *rv = new _list(this->c - other.c);
            return *rv;
        };

        _list operator*(_list other) {
            _list *rv = new _list(this->c * other.c);
            return *rv;
        };

        _list operator/(_list other) {
            _list *rv = new _list(this->c / other.c);
            return *rv;
        };

        _list operator++() {
            _list *rv = new _list(this->c++);
            return *rv;
        };

        _list operator--() {
            _list *rv = new _list(this->c--);
            return *rv;
        };

        _list operator<<(_list other) {
            _list *rv = new _list(this->c << other.c);
            return *rv;
        };

        _list operator>>(any other) {
            _list *rv = new _list(this->c >> other.c);
            return *rv;
        };

        _list operator^(_list other) {
            _list *rv = new _list(this->c ^ other.c);
            return *rv;
        };

        _bool operator!() {
            return !this->c;
        };

        _list operator~() {
            _list *rv = new _list(~this->c);
            return *rv;
        };

        _bool operator==(_list other) {
            return this->c == other.c;
        };

        _bool operator!=(_list other) {
            return this->c != other.c;
        };

        _bool operator>(_list other) {
            return this->c > other.c;
        };

        _bool operator<(_list other) {
            return this->c < other.c;
        };

        _bool operator<=(_list other) {
            return this->c <= other.c;
        };

        _bool operator>=(_list other) {
            return this->c >= other.c;
        };

        _bool operator&&(_list other) {
            return this->c && other.c;
        };

        _bool operator||(_list other) {
            return this->c || other.c;
        };

        _list operator&(_list other) {
            return this->c & other.c;
        };

        _list operator|(_list other) {
            return this->c | other.c;
        };
    };
};
