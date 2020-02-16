section .data
	p DB "Digite um número: "
	len_p  equ $-p
	pp DB "Digite o segundo número: "
	len_pp equ $-pp

	m DB "Resultado: "
	len_m equ $-m




section .bss
	; Reservando espaço de 1 byte para posterior uso. No nosso caso, troca-se apenas o D por RES
	numero RESB 2
	resultado RESB 2
	segundo RESB 2

section .text

global _start

_start:
	; Qualquer instrução do trecho de programa _main ficará aqui. Neste caso, _start é um rótulo dado á este trecho específico de programa
	;incrementa ; Execução do rótulo abaixo
	mov edx, len_p
	mov ecx, p
	mov eax, 4
	mov ebx, 1
	int 0x80

	mov eax, 3
	mov ebx, 0
	mov edx, 2
	mov ecx, numero
	int 0x80

	mov edx, len_pp
	mov ecx, pp
	mov eax, 4
	mov ebx, 1
	int 0x80

	mov eax, 3
	mov ebx, 0
	mov edx, 2
	mov ecx, segundo
	int 0x80

	mov edx, len_m
	mov ecx, m
	mov eax, 4
	mov ebx, 1
	int 0x80


	mov bl, [segundo]
	mov al, [numero]
	
	sub bl, '0' ; Convertendo valor de ASCII em decimal para fins de operação


	add al, bl
	
	mov [resultado], al

	mov ecx, resultado
	mov edx, 2
	mov eax, 4
	mov ebx, 1
	int 0x80

	mov eax,1 ; SAIDA
	int 0x80


; Rótulos são nada mais que porções de memória do processador separadas para executar determinado conjunto de instruções presente no conteúdo de cada rótulo
