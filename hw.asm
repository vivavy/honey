format ELF

public _start
extrn hny%%io%%print

_start:
    call hny%%main
    mov ebx, eax
    mov eax, 1
    int 0x80

hny%%main:
    enter 0, 0

    push hny%%__CONST0__
    call hny%%io%%print

    mov eax, 0
    leave
    ret

hny%%__CONST0__:
    dd 14
    db "Hello, World!", 10, 0
