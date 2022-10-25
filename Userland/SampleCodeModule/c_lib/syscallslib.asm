GLOBAL sys_write

GLOBAL sys_read

sys_write:
    mov rax,2
    int 80h
    ret

sys_read:
    mov rax,1
    int 80h
    ret