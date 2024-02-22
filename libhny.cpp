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

class __hny_str {
    public:
    __hny_str(){
        this->c_str = (const char *)0;
        this->length = 0;
    }
    __hny_str(const char *c_str) {
        this->c_str = c_str;
        this->length = strlen(c_str);
    }

    explicit operator bool() const {
        return (this->c_str ? true : false);
    }
    __hny_uint length;
    const char *c_str;
};

class __hny_bytes {
    public:
    __hny_uint length;
    __hny_u8 *buffer;
};

typedef double __hny_float;
typedef void __hny_nil;
typedef int __hny_bool;

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
class __hny_list
{
    public:
    T value;
    __hny_list<T> *next;
    __hny_list(){
        this->value = (T)0;
        this->next = (__hny_list<T>*)0;
    };

    __hny_nil $append(T value) {
        if (this->value)
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
        if (this->value == (T)0)
            __hny_exception_OutOfBounds(this, "attempt to pop value from empty list");
        rvalue = this->value;
        this->value = (T)0;
        return rvalue;
    };

    T $getitem(__hny_int index) {
        if (this->value == (T)0)
            __hny_exception_OutOfBounds(this, "index out of bounds");
        if (index)
            return this->next->$getitem(--index);
        return this->value;
    };

    __hny_nil $setitem(__hny_int index, T value) {
        if (this->value == (T)0)
            __hny_exception_OutOfBounds(this, "index out of bounds");
        if (index)
            return this->next->$setitem(--index, value);
        this->value = value;
    };
};
