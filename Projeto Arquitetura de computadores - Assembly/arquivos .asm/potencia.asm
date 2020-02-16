section .data
	p DB "DIGITE O NUMERO",0xA,0xD
	l_p equ $ - p
		
section .bss
x RESB 2
r RESD 2


; Procedure que faz potenciacao

;%macro potencia 1
;	mov al, byte [%1]
;	mov bl, [%1]
;	sub al, '0'
;	sub bl, '0'
;	mul bl
;	add al, '0'
;	mov [r], al		
;%endmacro

%macro potencia 1
	mov al, byte [%1]
	mov bl, [%1]
	sub al, '0'
	sub bl, '0'
	mul bl
	add eax, '0'
	mov [r], eax		
%endmacro

section .text

global _start
	
_start:
	mov eax, 4
	mov edx, l_p
	mov ecx, p
	mov ebx, 1
	int 0x80

	mov eax, 3
	mov edx, 1
	mov ecx, x
	mov ebx, 2
	int 0x80
	
	potencia x ; Execução da procedure passando x como parâmetro
	
	mov eax, 4
	mov edx, 1
	mov ecx, r
	mov ebx, 1
	int 0x80

	jmp sair

sair:
	mov eax, 1
	mov ebx, 0
	int 0x80


