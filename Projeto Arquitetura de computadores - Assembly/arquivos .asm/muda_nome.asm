section .data
name DB "OI"
len_n equ $-name
msg DB "VARIÁVEL NOME"
len_msg equ $-msg
msg2 DB "NOVA VARIÁVEL NOME"
len_msg2 equ $-msg2



section .bss

section .text

global _start

_start:
	
	mov edx, len_msg
	mov ecx, msg
	mov eax, 4
	mov ebx, 1
	int 0x80

	mov edx, len_n
	mov ecx, name
	mov eax, 4
	mov ebx, 1
	int 0x80

	mov edx, len_msg2
	mov ecx, msg2
	mov eax, 4
	mov ebx, 1
	int 0x80


	mov [name], dword 'Ou'
	mov edx, 2
	mov ecx, name
	mov eax, 4
	mov ebx, 1
	int 0x80

	mov eax, 1
	int 0x80
