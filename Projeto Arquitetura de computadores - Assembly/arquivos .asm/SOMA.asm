section .bss
	N1		resb 100
	N2 		resb 100
	Sum 	resb 100
	tam		resd 1 			; auxiliar
	number1 resd 1
	number2 resd 1
	soma 	resd 1
	erro 	resd 1			; '1' tamanho errado ; '2' entrada nao numerica ; '0' ta de boa
	 
section .data
	Msg1 db "Digite a primeira parcela: ",endl
	tamMsg1 equ $- Msg1
	
	Msg2 db "Digite a segunda parcela: ",endl
	tamMsg2 equ $- Msg2
	
	Msg3 db "Resultado da Soma das Duas Parcelas: ",endl
	tamMsg3 equ $- Msg3
	
	MsgERRO1 db "ENTRADA NAO NUMERICA...",endl
	tamMsgERRO1 equ $- MsgERRO1

	MsgERRO2 db "NO MAXIMO 6 DIGITOS OU NO MINIMO 1 !!!",endl
	tamMsgERRO2 equ $- MsgERRO2

endl equ 10		; macro quebra de linha  

section .text



IMPRIME_SOMA:	
	mov ebx,1
	mov eax,4
	mov edx,[tam]
	mov ecx,Sum
	int 0x80	
ret 	

MSG1:	
	mov ebx,1
	mov eax,4
	mov edx,tamMsg1
	mov ecx,Msg1
	int 0x80	
ret 	

MSG2:
	mov ebx,1
	mov eax,4
	mov edx,tamMsg2
	mov ecx,Msg2
	int 0x80
ret

MSG3:
	mov ebx,1
	mov eax,4
	mov edx,tamMsg3
	mov ecx,Msg3
	int 0x80
ret


LEITURA1:
	mov edx,100
	mov ecx,N1
	mov ebx,0
	mov eax,3
	int 0x80
ret

LEITURA2:
	mov edx,100
	mov ecx,N2
	mov ebx,0
	mov eax,3
	int 0x80
ret

VALIDA_E_CONVERTE1: ; converte para inteiro	; em eax vai estar o tamanho da frase lida
	
;	mov eax,dword[tam]
	dec eax
	jz ERR2
	cmp eax,6
	jg ERR2							;;;;;;;;;;;;;;;;;;;;;
	
	mov dword[erro],0 				; ta de boa
	mov dword[number1],0			; inicializa
	mov edi,eax						; edi e o final da srting 
	mov esi,0						; esié posicao atual
	mov ecx,0
	
	mov ebx,0
	
	LOOP1:	
		mov cl,[N1 + esi]			; aponta para posicao esi de N1
		sub cl,48					; tabela ASCII	
		
		cmp cl,9					;  cl e numero ?
		ja	ERR1					;  cl não é numero, entao vai para err1, senão continua
		
		mov edx,0 					;  prepara edx para multiplicacao
		mov eax,10					;  prepara eax para multiplicacao		
		mul ebx						;  edx:eax = edx:eax * ecx
		
		mov ebx,eax
		add ebx,ecx
	
		inc esi 		 		  	; proxima posicao
		cmp esi,edi 				; chegou ao final?
		je SAI1						; se sim, vai embora, se nao continua
	jmp LOOP1
	
	ERR1:
		mov dword[erro],1
		jmp SAI1
	ERR2:	
		mov dword[erro],2
	SAI1:		; entao se deu tudo certo em number1 tem a string n1 so que em inteiro, convertido!
	
	mov dword[number1],ebx		; coloca em number1 a soma atual
ret

VALIDA_E_CONVERTE2: ;converte para inteiro
	; em eax vai estar o tamanho da frase lida
	
	dec eax
	jz ERRR2
	cmp eax,6
	jg ERRR2 						; se eax maior que 6 
	
	mov dword[erro],0 				; ta de boa
	mov dword[number2],0			;
	mov edi,eax						;
						
	mov ecx,0
	xor ebx,ebx
	xor esi,esi						; pos atual
	
	LOOP2:
		mov cl,[N2 + esi]			; aponta para posicao esi de N1
		sub cl,48					; tabela ASCII	
		
		cmp cl,9					;  cl e numero ?
		ja	ERRR1					;  cl não é numero, entao vai para err1, senão continua
		
		mov edx,0 					;  prepara edx para multiplicacao
		mov eax,10					;  prepara eax para multiplicacao		
		mul ebx						;  edx:eax = edx:eax * ecx
		
		mov ebx,eax
		add ebx,ecx
		
		
		inc esi 		 		  	; proxima posicao
		cmp esi,edi 				; chegou ao final?
		je SAII2					; se sim, vai embora, se nao continua
	jmp LOOP2
	
	ERRR1:
		mov dword[erro],1
		jmp SAII2
	ERRR2:	
		mov dword[erro],2
	SAII2:		; entao se deu tudo certo em number2 tem a string n2 so que em inteiro, convertido!
		
	mov dword[number2],ebx		; coloca em number1 a soma atual

ret

SOMA: ; soma number1 e number 2
	xor eax,eax
	mov eax,dword[number1]
	add eax,dword[number2]
	mov dword[soma],eax
ret

CAST_INT_STRING: ; uso da pilha para essa conversao

	;carregar em eax a variavel que queremos colocar converter
	
	xor esi,esi				; vai conter a quantidade de digitos
	mov eax,dword[soma]			;
	mov ecx,10					;	
	
	LOOP3:						;
		inc esi					;
		mov rdx, 0
		div ecx					;
		add edx,48				;
		push rdx
		cmp eax,0				;
		jz SAIII				;				
	jmp LOOP3					;
	SAIII:
	
	mov ebx,0
	mov dword[tam],esi
	inc dword[tam]
	mov edx,10
	mov [Sum + esi],edx
	
	LOOP4:
		cmp esi,0
		je SAIIII
		pop rdx
		mov [Sum + ebx],dl		; coloca aonde quero
		dec esi
		inc ebx
	jmp LOOP4
	
	SAIIII:
	
ret


TRATA_ERRO1_1:
	mov ebx,1
	mov eax,4
	mov edx,tamMsgERRO1
	mov ecx,MsgERRO1
	int 0x80
	jmp FOR
ret

TRATA_ERRO1_2:
	mov ebx,1
	mov eax,4
	mov edx,tamMsgERRO2
	mov ecx,MsgERRO2
	int 0x80	
	jmp FOR
ret

TRATA_ERRO2_1:
	mov ebx,1
	mov eax,4
	mov edx,tamMsgERRO1
	mov ecx,MsgERRO1
	int 0x80	
	jmp FOR2
ret

TRATA_ERRO2_2:
	mov ebx,1
	mov eax,4
	mov edx,tamMsgERRO2
	mov ecx,MsgERRO2
	int 0x80	
	jmp FOR2
ret


global main
main:
	
	FOR:	;enquanto o usuario estiver digitando errado, o laço vai acontecer
		call MSG1							;
		call LEITURA1						;
		mov dword[tam],eax
		call VALIDA_E_CONVERTE1				;
		cmp dword[erro],1					;
		je TRATA_ERRO1_1					;
		cmp dword[erro],2					;
		je TRATA_ERRO1_2					;	
		
		FOR2:								;
			call MSG2						; imprime msg2 na tela
			call LEITURA2					; le o que o usuario digita
			mov dword[tam],eax
			call VALIDA_E_CONVERTE2			; valida e converte o que foi lido		
			cmp dword[erro],1				; se tem erro, trata
			je TRATA_ERRO2_1				; 
			cmp dword[erro],2				; se tem erro, trata
			je TRATA_ERRO2_2				;	
		
		call SOMA							; execulta a soma
		call CAST_INT_STRING				; transforma int para string (soma)
		call MSG3							; imprime a msg 3 na tela
		call IMPRIME_SOMA					; imprime a soma na tela(em string)

jmp main						
mov ebx,0	; retorno esta em ebx
mov eax,1	; Serviço (exit), de paramentro 1
int 0x80	; Executa ação prevista(exit)
