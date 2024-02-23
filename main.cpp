#include <libhny.hpp>
#include <stdlib/io.hpp>


namespace hny {
    hny::_int _main(hny::_int argc, hny::_str execp) {
        rt::push("function \"main\"");
        _print("Hello, World!\n");
        rt::pop();
        return 0;
    };
};

int main(int argc, const char **argv) {
    return hny::_main(hny::_int(argc), hny::_str(argv[0])).__to_c();
};
