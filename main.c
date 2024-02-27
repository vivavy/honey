#include <libhny.h>
#include <stdlib/io.h>

#include <stdio.h>

#define LOG(x) printf("%s", "[LOG] "); printf("%s", c); putc('\n', 0)


int $main($list$$str $args) {
    rt_push("function \"main\"");
    
    $print($str$$add($str$$new$_$uint($list$$str$length($args)), $str$$new$_$charptr("\n")));

    rt_pop();
    return 0;
};

int main(int argc, char **argv) {
    $list$$str args = $list$$str$$new();
    for (unsigned i = 0; i < argc; i++)
        $list$$str$append(args, argv[i]);  // type: ignore
    return $main(args);
};
