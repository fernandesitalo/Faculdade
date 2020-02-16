section .data
	msg DB "Digite a base do triangulo" ,0xa
	l_msg equ $ - msg
	msg2 DB "Digite a altura do triangulo", 0xa
	l_msg2 equ $ - msg2
	msg3 DB "Resultado", 0xa
	l_msg3 equ $ - msg3

	divisor DB '2'
	
section .bss
	base RESB 1
	altura RESB 1
	area RESB 2

section .text

global _start
	
_start:
	mov eax, 4
	mov ebx, 1
	mov edx, l_msg
	mov ecx, msg
	int 0x80

	mov eax, 3
	mov ebx, 2
	mov ecx, base
	mov edx, 2
	int 0x80

	mov eax, 4
	mov ebx, 1
	mov edx, l_msg2
	mov ecx, msg2
	int 0x80

	mov eax, 3
	mov ebx, 2
	mov ecx, altura
	mov edx, 2
	int 0x80


	; Multiplicando base e altura
	sub [base], byte '0'
	sub [altura], byte '0'
	mov al, [base]
	mov bl, [altura]
	mul bl
	
	; Dividindo o produto por 2

	sub [divisor], BYTE '0'
	mov bl, [divisor]
	div bl	; Divisão do acumulador(AX) pelo divisor (bl) . No AX, está o resultado da multiplicação	
	add al, '0'
	mov [area], al

	mov eax, 4
	mov ebx, 1
	mov edx, l_msg3
	mov ecx, msg3
	int 0x80

	mov eax, 4
	mov ebx, 1
	mov edx, 2
	mov ecx, area
	int 0x80
	
	jmp sair

sair:
	mov eax, 1
	mov ebx, 0
	int 0x80
