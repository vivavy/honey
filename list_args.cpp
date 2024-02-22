#include "libhny.cpp"

__hny_int __hny_main(__hny_list<__hny_str> args);

int main(int argc, const char **argv) {
    __stack = new __hny_stack<__hny_str>();
    __hny_list<__hny_str> *args = new __hny_list<__hny_str>();
    for (int i = 0; i < argc; i++) args->$append(argv[i]);
    return __hny_main(*args);
};

__hny_int __hny_main(__hny_list<__hny_str> args) {
    __stack->$append("function \"main\"");

    __stack->$append("for each loop #1");
    for(__hny_str arg; !(arg = args.$iterate());) {
        __hny_print(arg);
    }
    __stack->$pop();

    __stack->$pop();
    return 0;
};