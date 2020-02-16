
section .bss ; aloca/reserva memoria
	strPC1 		resb 100 				; reservou 100 bytes para PARCELA 1
	strPC1_size equ $-strPC1			; tamanho da PARCELA 1
	
	strPC2 		resb 100 			 	; reservou 100 bytes para tamanho da PARCELA 2
	strPC2_size equ $-strPC2 		 	; TAMANHO DA PARCELA 2
	
	PC1 	resd	1	; PC1 -> Parcela1 da soma
	PC2 	resd	1	; PC2 -> Parcela2 da soma
	SUM		resd 	1	; SUM -> Soma das Parcelas 1 e 2
	coderro	resd 	1   ; coderro -> 1 - qtd de linhas 
	
	
section .data ; diretiva
	msgPC1 db "Digite a primeira Parcela da Soma: ",endl
	msgPC1_size equ $-msgPC1

	mensagemPC2 db "Digite a segunda Parcela da Soma: ",endl
	msgPC2_size equ $-msgPC2
	
	erro1 db "Entrada não numérica! Digite Novamente! ",endl
	erro1_size equ $-erro1
	
	erro2 db "Tamanho do numero invalido! Digite Novamente! ",endl
	erro2_size equ $-erro2
	
endl equ 10  	; macro/constante


global main
main:

	; -------------- impressão da mensagem --------
	mov eax,0
	mov eax,4
	mov edx,msgPC1
	mov ecx,msgPC1_size
	int 0x80	

	; ---------------- leitura da frase -----------
	mov edx,99
	mov ecx,PC1
	mov ebx,0
	mov eax,3
	int 0x80
	
	jmp VALIDA
	
	
	
	
	
	
	
;__________________________________
	VALIDA:
	
	mov [qtd] , eax			; mover o que esta em eax para qtd
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
		
	ret
;__________________________________
	
	






;------------ Finaliza progama -------
mov eax,1			; Serviço (exit), de paramentro 1
int 0x80			; Executa ação prevista(exit)



; EAX -> Acumulador
	;Utilizado em operações aritméticas, acesso de portas de entrada e saída, 
	;transferência de dados, entre outros.
; EBX -> Base
	; Base 	Utilizado como ponteiro para acessar a memória, 
	; índice, e auxiliar de operações aritméticas efetuadas por EAX.
; ECX -> Contador
	; Contador 	Sua principal finalidade é servir de contador em laços
	; de repetição.
; EDX -> Dados
	; Dados 	Usado em operações aritméticas juntamente com 
	; EAX (EDX recebe o resto da divisão e o produto da multiplicação), 
	; acesso de portas de entrada e saída, entre outros.
