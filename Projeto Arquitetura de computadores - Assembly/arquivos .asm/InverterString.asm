; mov -> modo de endereçamento

section .bss
	frase 			resb 100					; aloca memoria
	fraseInvertida 	resb 100					; aloca memoria
	qtd 			resd 1						; 
	tam_frase equ $- frase 						; conta o tamanho da frase 
	tam_fraseInvertida equ $- fraseInvertida	;



section .data
	mensagem db "Entre com uma frase: ",endl
	tam_mensagem equ $-mensagem
	

endl equ 10  	; macro/constante



global main
main:

	; -------------- impressão da mensagem --------
	mov eax,0
	mov eax,4
	mov edx,tam_mensagem
	mov ecx,mensagem
	int 0x80
	;-----------
	
	
	
	; ---------------- leitura da frase -----------
	mov edx,99
	mov ecx,frase
	mov ebx,0
	mov eax,3
	int 0x80
	;------------
	
	
	
	; ---------------- inversao da frase ----------
	
	mov [qtd],eax			; mover o que esta em eax para qtd
	mov esi,0 				; inicializa contador registrador frase
	mov edi,[qtd]			; inicializa contador registrador fraseInvertida
	
	loop:		
			dec edi  		; decrementa contador fraseInvertida
			cmp edi,0		; comparacao do contador edi com zero
			je sai			; 'if' edi igual a 0 vai para subrotina 'sai'
			
			mov al,[frase + esi]
			mov [fraseInvertida + edi],al
			
			inc esi			; incrementa contador frase
	jmp loop
	
	
	sai: 						; subrotina 'sai'
	
		
	;---------------------------- impressão da String --------------------
	mov ebx,0							; Saida para o Monitor
	mov eax,4							; Serviço de impressao
	mov edx,tam_fraseInvertida			; Tamanho  da mensagem
	mov ecx,fraseInvertida				; endereco de memoria da mensagem
	int 0x80							; executa a ação definida
	
	
	;---------------------------- Finaliza progama -----------------------
	mov eax,1							; Serviço (exit), de paramentro 1
	int 0x80							; Executa ação prevista(exit)
