#pragma once

#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)
#define NEW(type,name,args) type *name = new type args

typedef char *$str;
typedef int $int;
typedef struct {
    $str data;
    unsigned next;
    unsigned prev;
} $list$$str$$node;
typedef struct {
    $str *head;
    $str *tail;
} $list$$str;
typedef $str $err;

