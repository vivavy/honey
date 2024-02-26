#include <libhny.h>
#include <stdlib/io.h>

#include <stdio.h>

#define LOG(x) printf("%s", "[LOG] "); printf("%s", c); putc('\n', 0)


int $main($list$$str $args) {
    rt_push("function \"main\"");
    
    $print($str$$new($list_str$length($args)) + "\n");

    rt_pop();
    return 0;
};

int main(int argc, const char **argv) {
    $list$$str args = $list$str$$new();
    for (unsigned i = 0; i < argc; i++)
        $list$$str$append(args, argv[i]);
    return $main(args);
};
