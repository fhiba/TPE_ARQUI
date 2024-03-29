section .text
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
GLOBAL sys_divzero
GLOBAL sys_opcode
GLOBAL sys_recto
GLOBAL sys_tron
GLOBAL sys_beep
GLOBAL sys_printBase
GLOBAL sys_isBlackPixel
sys_write:
    mov rax, 2
    int 80h
    ret

sys_read:
    mov rax, 1
    int 80h
    ret

sys_beep:
    mov rax, 17
    int 80h
    ret

sys_printMem:
    mov rax, 40
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

sys_tron:
    mov rax,13
    int 80h
    ret

sys_divzero:
    mov rax, 14
    int 80h
    ret

sys_opcode:
    mov rax, 15
    int 80h
    ret

sys_recto:
    mov rax,16
    int 80h
    ret


sys_printBase:
    mov rax, 20
    int 80h
    ret

sys_isBlackPixel:
    mov rax, 23
    int 80h
    ret

opcodetest:
    push rbp
    mov rbp, rsp
    mov cr6, rax
    mov rsp, rbp
    pop rbp
    ret

