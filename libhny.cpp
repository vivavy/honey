#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned long __hny_uint;
typedef signed long __hny_int;
typedef unsigned char __hny_u8;
typedef signed char __hny_i8;
typedef unsigned short __hny_u16;
typedef signed short __hny_i16;
typedef unsigned long __hny_u32;
typedef signed long __hny_i32;
typedef unsigned long long __hny_u64;
typedef signed long long __hny_i64;
typedef double __hny_float;
typedef void __hny_nil;
typedef int __hny_bool;

class __hny_str {
    public:
    __hny_str(){
        this->c_str = nullptr;
        this->length = 0;
    }
    __hny_str(const char *c_str) {
        if(!c_str) return;

        this->c_str = new char[strlen(c_str)];
        this->c_str[strlen(c_str) - 1] = 0;

        char c;
        for (int i = 0; (c = c_str[i]); i++) this->c_str[i] = c;
        if (c_str == nullptr) this->length = 0;
        else this->length = strlen(c_str);
    }

    __hny_str operator+(__hny_str other) {
        __hny_str *rvalue = new __hny_str();
        rvalue->c_str = new char[this->length + other.length];
        rvalue->length = this->length + other.length;
        rvalue->c_str[this->length + other.length - 1] = 0;
        char c;
        for (int i = 0; (c = this->c_str[i]); i++) rvalue->c_str[i] = c;
        for (int i = 0; (c = other.c_str[i]); i++) rvalue->c_str[this->length + i] = c;
        return *rvalue;
    }

    bool operator==(__hny_str *other) {
        return this == other;
    }

    explicit operator bool() const {
        return (this->c_str ? true : false);
    }

    __hny_uint get_length() {
        return this->length;
    }

    __hny_uint length;

    char *c_str;
};

template<typename T>
class __hny_array
{
    public:
    T *arr;
    __hny_array(T *arr) {
        this->arr = arr;
    };
    T $getitem(__hny_int index) {
        return this->arr[index];
    }
};

template <typename T>
class __hny_stack
{
    public:
    T value;
    __hny_stack<T> *next;
    __hny_stack(){
        this->value = nullptr;
        this->next = nullptr;
        this->iterator = 0;
    };

    __hny_nil $append(T value) {
        if (this->value == nullptr)
            if (this->next)
                this->next->$append(value);
            else {
                this->next = (__hny_stack<T>*)malloc(sizeof(__hny_stack<T>));
                this->next->$append(value);
            }
        else this->value = value;
    };

    __hny_stack<T>* operator*() {
        return this;
    };

    T $pop() {
        T rvalue;
        if (this->next)
            return this->next->$pop();
        if (this->value == nullptr)
            return nullptr;
        rvalue = this->value;
        this->value = nullptr;
        return rvalue;
    };

    T $getitem(__hny_int index) {
        if (this->value == nullptr)
            return nullptr;
        if (index)
            return this->next->$getitem(--index);
        return this->value;
    };

    __hny_nil $setitem(__hny_int index, T value) {
        if (this->value == nullptr)
            return;
        if (index)
            return this->next->$setitem(--index, value);
        this->value = value;
    };

    __hny_uint get_length() {
        if (this->value == nullptr)
            if (this->next)
                return 1 + this->next->get_length();
        else if (this->next) return 1;
        return 0;
    }

    T $iterate() {
        if (this->iterator >= this->get_length()) {
            this->iterator = 0;  // reset iterator
            return T();
        };
        return this->$getitem(this->iterator++);
    }

    __hny_uint iterator;
};

static __hny_stack<__hny_str> *$stack;

__hny_nil __hny_print(__hny_str value) {
    if(c_str) puts(value.c_str);
};
__hny_nil __hny_print_stderr(__hny_str value) {
    if(c_str) fputs(value.c_str, stderr);
};

__hny_nil __hny_exception_OutOfBounds(__hny_str description) {
    __hny_print_stderr("error occurred, stack trace:\n");
    for (__hny_str stage; (stage = $stack->$iterate());)
        __hny_print_stderr(__hny_str("    ") + stage + __hny_str("\n"));
    __hny_print_stderr(__hny_str("OutOfBounds: ") + description);
};


template <typename T>
class __hny_list
{
    public:
    T value;
    __hny_list<T> *next;
    __hny_list(){
        this->value = (T)0;
        this->next = (__hny_list<T>*)0;
        this->iterator = 0;
    };

    __hny_nil $append(T value) {
        if (this->value == nullptr)
            if (this->next)
                this->next->$append(value);
            else {
                this->next = (__hny_list<T>*)malloc(sizeof(__hny_list<T>));
                this->next->$append(value);
            }
        else this->value = value;
    };

    __hny_list<T>* operator*() {
        return this;
    };

    T $pop() {
        T rvalue;
        if (this->next)
            if (this->next->next) return this->next->$pop();
            rvalue = this->next->value;
            this->next = (__hny_list<T>*)0;
            return rvalue;
        if (this->value == nullptr)
            __hny_exception_OutOfBounds("attempt to pop value from empty list");
        rvalue = this->value;
        this->value = nullptr;
        return rvalue;
    };

    T $getitem(__hny_int index) {
        if (this->value == nullptr)
            __hny_exception_OutOfBounds("index out of bounds");
        if (index)
            return this->next->$getitem(index - 1);
        return this->value;
    };

    __hny_nil $setitem(__hny_int index, T value) {
        if (this->value == nullptr)
            __hny_exception_OutOfBounds("index out of bounds");
        if (index)
            return this->next->$setitem(--index, value);
        this->value = value;
    };

    __hny_uint get_length() {
        if (this->value == nullptr)
            return 0;
        if (this->next == nullptr)
            return 1;
        return this->next->get_length() + 1;
    }

    T $iterate() {
        if (this->iterator >= this->get_length()) {
            this->iterator = 0;  // reset iterator
            return nullptr;
        };
        return this->$getitem(this->iterator++);
    }

    __hny_uint iterator;
};
