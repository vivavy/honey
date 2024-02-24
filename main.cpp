#include <libhny.hpp>
#include <stdlib/io.hpp>


namespace hny {
    _int _main(_list<_str> args) {
        rt::push("function \"main\"");
        
        rt::push("for loop #0");

        for (_uint i = 0; i < args.length(); i = i + 1)
            _print(args.__getitem(i) + "\n");
        
        rt::pop();

        rt::pop();
        return 0;
    };
};

int main(int argc, const char **argv) {
    hny::_list<hny::_str> args;
    for (uint i = 0; i < argc; i++)
        args.append(argv[i]);
    return hny::_main(args).__to_c();
};
