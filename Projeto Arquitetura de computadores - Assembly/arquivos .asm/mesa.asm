section .data
	p DB "Lidando com matrizes", 0xa
	ln_p  equ $ - p
	b TIMES 2 DB 5 ; Instanciação do array b
	sum DB 0

section .bss


section .text

global _start

_start:
	mov ecx, p
	mov edx, ln_p
	mov eax, 4
	mov ebx, 1
	int 0x80

	
	mov eax, 2
	mov ecx, 1
	mov al, [b]
	mov [b], BYTE 3 ; Adicionando novo valor ao array b
	mov [b], BYTE 4 
	add al, [b]
	add al, '0'
	mov [sum], al
	
	mov eax, 4
	mov ebx, 1
	mov ecx, sum
	mov edx, 1
	int 0x80

	mov eax, 1
	int 0x80	
		
