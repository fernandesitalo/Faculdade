section .bss ; aloca/reserva memoria
	frase resb 60 ; reservou 60 byts 
	size_frase equ $-frase

section .data ; diretiva
	mensagem db "Entre com uma frase: ",endl
	tam equ $-mensagem

endl equ 10  	; macro/constante

global main
main:
	
	
	;---------- impressão --------------	
	mov ebx,0			; Saida para o Monitor
	mov eax,4			; Serviço de impressao
	mov edx,tam 		; Tamanho  da mensagem
	mov ecx,mensagem	; endereco de memoria da mensagem
	int 0x80			; executa a ação definida
	
	
	;----------- leitura string ---------
	mov edx,59			; Servico registrador,paramentro
	mov ecx,frase  		; Servico registrador,paramentro
	mov ebx,0   		; Servico registrador,paramentro - recebe do teclado
	mov eax,3			; Servico registrador,paramentro - faz a leitura
	int 0x80			; execulta a ação definida
	
	
	;------------
	mov ebx,0			; Saida para o Monitor
	mov eax,4			; Serviço de impressao
	mov edx,size_frase	; Tamanho  da mensagem
	mov ecx,frase		; endereco de memoria da mensagem
	int 0x80			; executa a ação definida
	
	
	
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
	
