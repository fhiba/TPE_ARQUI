GLOBAL cpuVendor
GLOBAL getKey
GLOBAL saveRegisters
GLOBAL rtcGet
section .text
	
cpuVendor:
	push rbp
	mov rbp, rsp

	push rbx

	mov rax, 0
	cpuid


	mov [rdi], ebx
	mov [rdi + 4], edx
	mov [rdi + 8], ecx

	mov byte [rdi+13], 0

	mov rax, rdi

	pop rbx

	mov rsp, rbp
	pop rbp
	ret

getKey:
        push rbp
        mov rbp, rsp

        mov rax,0           ;kbFlag

        in al,0x64          ;guardo en al el status del teclado 
        and al,0x01         ;hago la mascara del status para obetener el bit de input disponible
        cmp al,1            ;verifico que esté prendido el bit de input disponible
        jne .end            ;si no lo esta salto al final(la funcion devuelve scancode 0)
        in al,0x60          ;en caso de haber input lo cargo en el registro a

.end    mov rsp, rbp
        pop rbp
        ret

rtcGet:
	push rbp
	mov rbp, rsp

	mov al, dil
	out 0x70, al
	in al, 0x71

	mov rsp, rbp
	pop rbp
	ret


saveRegisters:
	mov [rdi+2*8], rbx
	mov [rdi+3*8], rcx
	mov [rdi+4*8], rdx
	mov [rdi+5*8], rsi
	mov [rdi+6*8], rdi
	mov [rdi+7*8], rbp
	mov [rdi+8*8], rsp
	mov [rdi+9*8], r8
	mov [rdi+10*8], r9
	mov [rdi+11*8], r10
	mov [rdi+12*8], r11
	mov [rdi+13*8], r12
	mov [rdi+14*8], r13
	mov [rdi+15*8], r14
	mov [rdi+16*8], r15
	push rbx
	mov rbx,[rsp+8]
	mov [rdi], rbx
	pop rbx
	ret
	