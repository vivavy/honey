#pragma once

#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)
#define NEW(type,name,args) type *name = new type args

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef char *$str;

typedef int $int;
typedef unsigned int $uint;
typedef uint8_t $u8;
typedef int8_t $i8;
typedef uint16_t $u16;
typedef int16_t $i16;
typedef uint32_t $u32;
typedef int32_t $i32;
typedef uint64_t $u64;
typedef int64_t $i64;

typedef struct {
    $str data;
    void *next;
    void *prev;
} $list$$str$$node;
typedef struct {
    $list$$str$$node *head;
    $list$$str$$node *tail;
} $list$$str;
typedef $str $err;

// prototypes
$str $str$$new(char *);
$str $str$$add($str, $str);
$str $str$$copy($str);

$list$$str $list$$str$$new();
void $list$$str$append($list$$str, $str);
$uint $list$$str$length($list$$str);

$str $str$$new$_$charptr(char *c_str) {
    return $str$$copy(($str)c_str);
};

$str $str$$new$_$uint($uint value) {
    if (!value) return $str$$new$_$charptr("0");

    $u64 power = 0;
    $uint c2 = value;
    while (c2) {
        power++;
        c2 /= 10;
    }
    $str rv = ($str)malloc(power);
    rv[power] = '\0';
    sprintf(rv, "%u", value);

    return rv;
}

$str $str$$add($str self, $str other) {
    $str rv = ($str)malloc(strlen(self) + strlen(other));
    strcpy(rv, self);
    strcpy(($str)(($u64)rv + strlen(self)), other);
    return rv;
}

$str $str$$copy($str self) {
    $str rv = ($str)malloc(strlen(self));
    strcpy(rv, self);
    return rv;
}

$list$$str $list$$str$$new() {
    $list$$str *rv = ($list$$str *)malloc(sizeof($list$$str));
    rv->head = rv->tail = (void *)0;
    return *rv;
}

void $list$$str$append($list$$str self, $str value) {
    $list$$str$$node *temp = ($list$$str$$node *)malloc(sizeof($list$$str$$node));
    temp->data = $str$$copy(value);

    if (self.head == ($list$$str$$node *)0) {
        self.head = temp;
    }
}

$uint $list$$str$length($list$$str self) {
    $uint rv = 0;

    if ((unsigned)self.head == 0)
        return 0;

    $list$$str$$node current = *(($list$$str$$node *)self.head);

    while ((uint64_t)current.next) {
        current = *(($list$$str$$node *)current.next);
        rv++;
    }

    return rv;
}

