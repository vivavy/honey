#include "libhny.cpp"

__hny_int __hny_main(__hny_list<__hny_str> args);

int main(int argc, const char **argv) {
    $stack = new __hny_stack<__hny_str>();
    __hny_list<__hny_str> *args = new __hny_list<__hny_str>();
    for (int i = 0; i < argc; i++) args->$append(argv[i]);
    return __hny_main(*args);
};

__hny_int __hny_main(__hny_list<__hny_str> args) {
    $stack->$append("function \"main\"");
    __hny_print("Hello, World!\n");
    $stack->$pop();
    return 0;
};
