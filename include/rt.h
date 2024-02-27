#pragma once

#include <base.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char *rt_stack[1024];
uint32_t rt_depth = 0UL;

#define rt_push(s) (rt_stack[rt_depth++] = s)
#define rt_pop() rt_depth--

$err $TypeError = "TypeError";
$err $NullError = "NullError";
$err $IndexError = "IndexError";

void $err$raise($err err, $str desc) {
    fprintf(stderr, "%s", "Error occurred\n");
    for (int i = 0; i < rt_depth; i++)
        fprintf(stderr, " in %s\n", rt_stack[i]);
    fprintf(stderr, "%s: %s\n", err, desc);
    exit(1);
}
