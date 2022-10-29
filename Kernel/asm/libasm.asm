GLOBAL cpuVendor
GLOBAL getKey

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

	mov al,dil
	out 0x70,al
	in al, 0x71

	mov rsp,rbp
	pop rbp
	ret