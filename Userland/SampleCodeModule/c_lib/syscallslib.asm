section .text
GLOBAL sys_write

sys_write:
    mov rax, 2
    int 80h
    ret