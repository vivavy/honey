#include "libhny.hpp"

__hny_int __hny_main(__hny_list<__hny_str> args);

int main(int argc, const char **argv) {
    $stack = new __hny_stack<__hny_str>();
    __hny_list<__hny_str> *args = new __hny_list<__hny_str>();
    for (int i = 0; i < argc; i++) args->$append(argv[i]);
    args->$append("Lol");
    args->$append("Kek");
    return __hny_main(*args);
};

__hny_int __hny_main(__hny_list<__hny_str> args) {
    $stack->$append("function \"main\"");

    $stack->$append("for each loop #1");
    for(__hny_str arg;;) {
        arg = args.$iterate();
        if (!arg) break;
        __hny_print(arg + "\n");
    }
    $stack->$pop();

    __hny_print(args.$getitem(0) + "\n");
    __hny_print(args.$getitem(1) + "\n");
    __hny_print(args.$getitem(2) + "\n");

    $stack->$pop();
    return 0;
};
