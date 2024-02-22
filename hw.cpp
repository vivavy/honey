#include "libhny.cpp"

__hny_int __hny_main(__hny_list<__hny_str> args);

int main(int argc, const char **argv) {
    __hny_list<__hny_str> args;
    for (int i = 0; i < argc; i++) args.$append(argv[i]);
    return __hny_main(args);
};

__hny_nil __hny_print(__hny_str value) {printf("%s", value.c_str);};

__hny_int __hny_main(__hny_list<__hny_str> args) {
    __hny_print("Hello, World!\n");
    return 0;
};
