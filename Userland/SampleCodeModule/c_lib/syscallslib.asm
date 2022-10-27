GLOBAL sys_write

GLOBAL sys_idle

sys_write:
    mov rax,2
    int 80h
    ret

sys_idle:
    mov rax,3
    int 80h
    ret