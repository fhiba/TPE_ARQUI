GLOBAL read 
Global write

read:
    mov rax,1
    int 80h
    ret


write:
    mov rax,2
    int 80h
    ret