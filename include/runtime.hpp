#pragma once

#include <base.hpp>
#include <iostream>

namespace hny {
    namespace rt {
        ulong call_stack_length = 0;
        char *call_stack[1024];

        void push(const char *s) {call_stack[call_stack_length++] = (char *)s;};
        void pop() {call_stack_length--;};

        class _error {
            const char *name;
            public:
            _error(const char *name) {
                this->name = name;
            }

            void raise(const char *desc) {
                std::cerr << "Error occurred, backtrace:\n";
                for (int i = 0; i < call_stack_length; i++)
                    std::cerr << '\t' << call_stack[i] << '\n';
                std::cerr << this->name << ": " << desc << '\n' << std::endl;
                exit(EXIT_FAILURE);
            };
        };

        class _warning {
            const char *name;
            public:
            _warning(const char *name) {
                this->name = name;
            }

            void raise(const char *desc) {
                std::cerr << "Warning:\n";
                for (int i = 0; i < call_stack_length; i++)
                    std::cerr << '\t' << call_stack[i] << '\n';
                std::cerr << this->name << ": " << desc << '\n' << std::endl;
            };
        };

        _error TypeError("TypeError");
        _error NullError("NullError");
    };
};
