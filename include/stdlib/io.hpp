#pragma once

#include <iostream>

namespace hny {
    inline void _print(_str s) {
        std::cout << s.__to_c();
    };
};
