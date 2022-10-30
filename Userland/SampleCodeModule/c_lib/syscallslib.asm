GLOBAL sys_write
GLOBAL sys_read
GLOBAL sys_printMem
GLOBAL sys_clear
GLOBAL sys_date
GLOBAL sys_sleep
GLOBAl sys_setScreen
GLOBAL sys_infoRegs
GLOBAL sys_getLast
GLOBAL sys_snapshotRegs
GLOBAL sys_resize
GLOBAL divzero
GLOBAL opcode

sys_write:
    mov rax, 2
    int 80h
    ret

sys_read:
    mov rax, 1
    int 80h
    ret

sys_printMem:
    mov rax, 4
    int 80h
    ret

sys_clear:
    mov rax, 3
    int 80h
    ret

sys_date:
    mov rax, 6
    int 80h
    ret

sys_sleep:
    mov rax, 7
    int 80h
    ret

sys_setScreen:
    mov rax, 8
    int 80h
    ret

sys_infoRegs:
    mov rax, 5
    int 80h
    ret

sys_snapshotRegs:
    mov rax, 12
    int 80h
    ret

sys_resize:
    mov rax,9
    int 80h
    ret

divzero:
    mov rax, 4
    xor rbx, rbx
    div rbx
    ret

opcode:
    ud2
    ret