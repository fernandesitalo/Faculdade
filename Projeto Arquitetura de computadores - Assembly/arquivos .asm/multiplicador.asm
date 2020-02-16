section .data
	p DB "Digite seu numero"
	l_p equ $ - p
	p2 DB "Voçê quer dobro ou triplo. 2 - DOBRO 3 - TRIPLO"
	l_p2 equ $ - p2

	r DB 0
		
section .bss
resp1 RESB 2
resp2 RESB 2
res RESB 2

section .text

global _start
	
_start:
	mov eax, 4
	mov ebx, 1
	mov edx, l_p2
	mov ecx, p2
	int 0x80

	mov eax, 3
	mov ebx, 2
	mov ecx, resp1
	mov edx, 2
	int 0x80

	mov eax, 4
	mov ebx, 1
	mov edx, l_p
	mov ecx, p
	int 0x80

	mov eax, 3
	mov ebx, 2
	mov ecx, resp2
	mov edx, 2
	int 0x80

	sub [resp1], BYTE '0'
	cmp [resp1], BYTE 2
	jz dobro

	cmp [resp1],BYTE  3
	jz triplo
	
	jmp sair

triplo:
	mov al, byte [resp2]
	mov bl, '3'
	sub al, '0'
	sub bl, '0'
	mul bl
	add al, '0'
	mov [r], al
	jmp exibir

dobro:
	mov al, byte [resp2]
	mov bl, '2'
	sub al, '0'
	sub bl, '0'
	mul bl
	add al, '0'
	mov [r], al
	jmp exibir

exibir:
	mov eax, 4
	mov ebx, 1
	mov ecx, r
	mov edx, 2
	int 0x80
	jmp sair

sair:
	mov eax, 1
	mov ebx, 0
	int 0x80
