section .data
	p DB "PRIMEIRA PERGUNTA", 0xa
	ln_p  equ $ - p
	p_d DB "SEGUNDA PERGUNTA", 0xa
	ln_p_d  equ $ - p_d
	r1 DB "OI"
	R2 DB "DOIS"
	ac DB "voce acertou"
	l_ac equ $ - ac
	ec DB "voce errou"	
	l_ec equ $ - ec
	l_r1 equ $ - r1
	fim DB "ACABOU"	
	l_f equ $ - fim

section .bss
resp1 RESB 2
resp2 RESB 2

section .text

global _start
	
_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, p
	mov edx, ln_p
	int 0x80

	mov eax, 3
	mov ebx, 2
	mov ecx, resp1
	mov edx, 2
	int 0x80

	mov esi, resp1
   	mov edi, r1
   	mov ecx, 2
   	cld ; Incrementa registradores de strings (Pula de um caracter para outro)
	repe  cmpsb ; REPE repete o comando cmpsb até ecx igualar á 0. O comando CMPSB compara valores de string que estao em ESI e EDI. 
	jecxz acertou    ; Pula  para o trecho acertou quando    
	jmp _start ; Quando o usuário erra, volta para este fluxo
	;jmp errou 
	jmp sair

acertou:
	mov eax, 4
	mov ebx, 1
	mov ecx, ac
	mov edx, l_ac
	int 0x80

segunda:
	mov eax, 4
	mov ebx, 1
	mov ecx, p_d
	mov edx, ln_p_d
	int 0x80

	mov eax, 3
	mov ebx, 2
	mov ecx, resp2
	mov edx, 4
	int 0x80

	mov esi, resp2
   	mov edi, R2
   	mov ecx, 2
   	cld 
	repe  cmpsb
	jecxz finish      
	jmp segunda 

errou:
	mov eax, 4
	mov ebx, 1
	mov ecx, ec
	mov edx, l_ec
	int 0x80
	jmp sair


finish:
	
	mov eax, 4
	mov ebx, 1
	mov ecx, fim
	mov edx, l_f
	int 0x80
	jmp sair


sair:
	mov eax, 1
	mov ebx, 0
	int 0x80
