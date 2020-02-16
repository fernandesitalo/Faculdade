
; ALUNO : ITALO FERNANDES GONÇALVES
; MATRICULA : 2016.1.0033.0542-0

; :::macros:::
; empilha todos registradores que queremos salvar o conteudo
; faz o que deve ser feito
; desempiha na ordem contraria de empilhento pra recuperar os dados

%macro print 2  ;(enderecoMSG,tamanhoMSG)
 push rax
 push rbx
 push rdx
 push rcx
	mov ecx,%1
	mov edx,%2
	mov ebx,1
	mov eax,4
	int 0x80
 pop rcx
 pop rdx
 pop rbx
 pop rax
%endmacro 
 
%macro scan 2 ;(endereco onde vou colocar a msg,tamanho da mesagem a ser lida) 
	mov ecx,%1
	mov edx,%2
	mov ebx,0
	mov eax,3
	int 0x80
%endmacro  

%macro ExitForca 0
  mov ebx,0
  mov eax,1
  int 0x80
%endmacro


section .bss
  mask		   resb 30
  PalavraChave resb 100
  Chute 	   resb 100
  Bloqueio     resb 100
  tam		   resd 2		; tamanho da palavraChave
  tentativas   resd 2		; quatidade de erros do jogo
  aux		   resb 10 
  flagletra	   resd 2
  restante	   resd 2
  errou		   resd 1
	
section .data
  msg1 db "VIDAS: "
  t_msg1 equ $-msg1
  msg2 db ">>>>> Entrada Invalida!",qdl,qdl
  t_msg2 equ $-msg2 
  msg3 db "Digite uma 'LETRA' ou um 'PALPITE': "
  t_msg3 equ $-msg3
  msg5 db "Digite a Palavra Chave (Nao Use Acentos): "
  t_msg5 equ $-msg5
  msg6 db "VOCE PERDEU!",qdl
  t_msg6 equ $-msg6
  msg7 db "VOCE GANHOU!",qdl
  t_msg7 equ $-msg7
  msg8 db "LETRA JA DIGITADA! PRESTE ATENCAO!",qdl,qdl,qdl
  t_msg8 equ $-msg8
  msg9 db "ERROOOOOOUUUUUUU!!!!!",qdl,qdl,qdl
  t_msg9 equ $-msg9
  msg10 db "LETRAS USADAS: "
  t_msg10 equ $-msg10
  msg11 db "Digite Alguma coisa Valida!!",qdl,qdl
  t_msg11 equ $-msg11
  resp db "A PALAVRA CHAVE ERA:   "
  t_resp equ $-resp
  limpaTela db 27, "[H", 27, "[2J"
  t_limpaTela equ $-limpaTela
  endl  db qdl,qdl,qdl,qdl,qdl
  traco db "_"
  espc  db " "	
  alfabeto db "ABCDEFGHIJKLMNOPQRSTUVWXYZ-----"
  boneco  db "_________________",10,"                 |",10,"               (º_º)",10,"                /|\ ",10,"                / \ ",10

qdl	equ 10






section .text

LIMPA_TELA:
 print limpaTela,t_limpaTela
ret


IMPRIME_BONECO:
	xor edi,edi
	add edi,37                ; desenho da forca
	cmp dword[tentativas],6   ; cabeça do boneco
	je .sai
	add edi,22
	cmp dword[tentativas],5   ; braco esquerdo 
	je .sai
	add edi,18
	cmp dword[tentativas],4   ; tronco
	je .sai
	add edi,1
	cmp dword[tentativas],3   ; braco direito
	je .sai
	add edi,1
	cmp dword[tentativas],2   ; perna esquerda
	je .sai
	add edi,20
	cmp dword[tentativas],1   ; perna direita
	je .sai
	add edi,3
.sai:
print boneco,edi
print endl,2
ret


; tem cl como parametro... verifica se cl e uma letra maiuscula.... retorna no proprio cl
IS_ALPHA: 
	cmp cl,'A' ; se cl e menor do que 'A', entao cl nao e letra
	jl nalpha	
	cmp cl,'Z' ; se cl e maior que 'Z' entao cl nao e letra
	jg nalpha
	mov cl,0
	ret
nalpha:
mov cl,1
ret



;compara posicao a posicao do chute com a palavra chave e retorna 1 ou 0 em [errou]
VERIFICA_CHUTE:
	; eax contem o tamanho do chute lido
	mov dword[errou],0 		;	inicializa
	dec eax								; ajeita tamanho
	cmp eax,[tam]					; primeira coisa pra dar certo, os tamanhos devem ser iguais
	jne chuteErrado				; se os tamanho são difererntes
	xor esi,esi
	fori:
		cmp esi,[tam]							; flag parada
		je chuteCerto
		mov cl,[PalavraChave+esi]
		cmp cl,[Chute+esi]
		jne chuteErrado
		inc esi										; contador indexador
	jmp fori
chuteErrado:
mov dword[errou],1
chuteCerto:
ret




; erro da letra: tamanho
VALIDA_LETRA: ; eax tem o tamanho -> parametro global
	mov dword[flagletra],0
	
	cmp dword[Chute], 91	; padroniza a letra.. verifica se esta maiuscula ou nao	
	jl OO					; se ja esta maiuscula, vai para OO
		sub dword[Chute],32	; transforma para maiuscula somando 32, TABELA ASCII 		
	OO:						; ta ok, pode retornar	
	
	
	mov cl,byte[Chute+0]	; paramentro IS_ALPHA
	call IS_ALPHA			; chamada	
	cmp cl,1				; retorno da funcao
	je tamanhoInvalido		; tamanho invalido	
		
		
	;ultima validacao
	xor eax,eax
	mov al,byte[Chute+0]
	sub eax,65
	
	; se em mask a letra tiver '1', e pq o cara ja digitou ela... '0' nao digou ainda...		
	cmp byte[mask+eax],'1' 
	je LetraJaDigitada
	
	;neste caso, e a primeira vez q ele digita a letra
	mov byte[mask+eax],'1'
	jmp saii
		
	tamanhoInvalido:			; label local	
		mov dword[flagletra],1	; flag de que a letra e invalida
		jmp saii
	
	LetraJaDigitada:
		mov dword[flagletra],2	; flag de que a letra ja foi digitada!
	
saii:
ret



; o chute fica todo em maiusculo tirando espacos e enter
PADRONIZA_CHUTE: 
	xor esi,esi
	f:
		cmp esi,[tam]
		jg s
		cmp byte[Chute+esi],' '
		je next
		cmp byte[Chute+esi],'-'
		je next
		cmp byte[Chute+esi],'Z'
		jl next
			sub byte[Chute+esi],32
		next:
		inc esi	
	jmp f
s:	
ret



INICIALIZA:
	xor esi,esi 					; zera contador que vai iterar sobre a string
	mov dword[restante],0			; contem o numero de letras que devem ser desbloqueadas
	mov dword[tentativas],6			; numero inicial de tentativas
	mov dword[errou],0
	cmp dword[tam],0
	je palavraInvalida
loop:
	cmp esi,[tam]					; condicao de parada do laço
	je sai							; sai do loop
	
	; padronizar tudo MAIUSCULO
	
	cmp byte[PalavraChave+esi],' '	; nao vou bloquear espacos.. eh sacanagem
	je livre 
	cmp byte[PalavraChave+esi],'-'	; nao vou bloquear o infem.. eh sacanagem tbmm
	je livre
	
	cmp byte[PalavraChave+esi],97
	jl LB	;jl-> menor que
		sub dword[PalavraChave+esi],32	;padroxizacao da palavra, isto eh, tudo maiusculo	
	LB:	
	
	mov cl,[PalavraChave+esi]	
		
	call IS_ALPHA									; vetifica se eh letra
	cmp cl,1											; paramentro global da funcao is_alpha
	je palavraInvalida						; palavra invalida...

	mov byte[Bloqueio+esi],'0'		; bloqueia a posicao da palavra
	inc esi 											; proximo index
	inc dword[restante]				 
	jmp loop
	
	livre:												; essa posicao nao pode ser bloqueada..
	mov byte[Bloqueio+esi],'1' 		; nao bloqueia a posicao da palavra
	inc esi												; proximo index
jmp loop	
sai:														; label de saida

xor esi,esi
lup:
	cmp esi,27
	je T
	mov byte[mask+esi],'0'
	inc esi
jmp lup

palavraInvalida:
mov dword[errou],1
T:	
ret									; finaliza a "chamada"


LETRAS_USADAS:
xor esi,esi
lyp:
	cmp esi,27
	je sain
	cmp byte[mask+esi],'1'
	je imprime
		inc esi
		jmp lyp
	imprime:
	mov ecx,alfabeto
	add ecx,esi
	print ecx,1
	print espc,1
	inc esi
jmp lyp	
sain:	
ret




IMPRIME_PALAVRA:
xor esi,esi							; zera o indexador do segmento
for:
	cmp esi,[tam]					; condicao de parada
	je caifora						; label para sair do laco de repeticao

	print espc,1
	
	cmp byte[Bloqueio+esi],'1'		; verifica se esta bloqueado ou nao a posicao
	je YU	
	
	print traco,1
	inc esi       			 		; proxima posicao
	jmp for

	YU:		      					; a letra nao esta bloqueada.. entao posso imprimi-la
	mov edi,PalavraChave
	add edi,esi	
	print edi,1
	inc esi		 				  	; proxima posicao
	
jmp for
caifora:
print endl,2
ret


VARRE_PALAVRA: 	
xor esi,esi						; zera indexador do segmento de texto
mov eax,[restante]
laco:
	cmp esi,[tam]				; condicao de parada
	je vaza						; sai do laco

	mov cl,[PalavraChave+esi]	; coloca em cl a posicao atual
	cmp cl,[Chute+0]			; compara com a letra digitada
	je desbloqueia				; se a letra for igual a que o cara digitou... entao desbloqueia

	inc esi						; proxima index da letra
	jmp laco					; caso contrario, vai pra proxima letra

	desbloqueia:				
		cmp byte[Bloqueio+esi],'1'
		je aki
		dec eax	
		mov byte[Bloqueio+esi],'1'	; coloca '1' na posicao esi sinalizando que ela foi desbloqueada
	aki:
	inc esi						; proximo index 

jmp laco
vaza:							; label de saida
ret 							; finaliza a "chamada"


global main
main:
	
	mov dword[errou],0
	
	jogador1:	

		cmp dword[errou],0
		je ok
			print msg11,t_msg11
		ok:
		print msg5,t_msg5 ; mensagem de orientacao ao usuario
		scan PalavraChave,100 ; leitura da palavra chave
		dec eax							;  tira o '\0' da string
		mov [tam],eax					; inicializa tam com o tamanho certo...
		call INICIALIZA					; vamos padronizar a palavraChave... alem de bloqueas as posicoes necessarias
		call LIMPA_TELA
		
	cmp dword[errou],1
	je jogador1
	
;------------------------------------ LOOP PRINCIPAL DO JOGO --------------------
  jogo:
	call LIMPA_TELA						
	
	cmp dword[flagletra],0		;
	je taCerto								;
	
		cmp dword[flagletra],2	
		je erro2								; erro2 -> mensagem de erro
		
		;erro1
		print msg2,t_msg2				; err1 -> mensagem de entrada invalida	
		jmp taCerto
		
		erro2:
		print msg8,t_msg8
		
	taCerto:					;
	
	cmp dword[errou],0			; errou 
	je cont									;			
		print msg9,t_msg9			; Mensagens 'Letra Usadas'
		mov dword[errou],0		;	
	cont:										;
				
	print msg10,t_msg10			;
	call LETRAS_USADAS			; imprime letras usadas
	print endl,4			
	
	call IMPRIME_BONECO			; imprime boneco
	print endl,1
	call IMPRIME_PALAVRA		;	imprime a balavra com os bloqueios
	print endl,1
	print msg1,t_msg1				; 'VIDAS: '

	mov eax,[tentativas]		
	add eax,'0'							
	mov dword[aux+0],eax		

	print aux,1							
	print endl,1						
	print msg3,t_msg3				; orientacao
	
	scan Chute,100					; leitura do chute ou tentativa
	
	cmp eax,1
	je jogo									; igual a 2 o tamanho, entao o cara 
													; digitou um enter.. a string so tem um '\0'	
	cmp eax,2
	je ehLetra
	
	; eh chute!!!!!!!!!!!
		call PADRONIZA_CHUTE
		call VERIFICA_CHUTE
		
		cmp dword[errou],1
		je errouu
		
		mov eax,0
		jmp acertou	
	
	ehLetra:
		call VALIDA_LETRA				;
		cmp dword[flagletra],0	; 1- entrada invalida, 2 - letra ja digitada
		jg jogo									; maior que zero
		call VARRE_PALAVRA			; percorre a palavra desbloqueando a letra digitada..
		; 4 byte/4byte	
		cmp eax,[restante]			; * qndo varrer a palavra dnv... eax vai ter a quantidade atual r
														; estante de letras a serem desbloqueadas
		je errouu								; * se a quantidade atual e igual a quantidade antiga, entao
														; o cara errou, nao desbloqueou nenhuma letra..
		
	acertou:
		mov [restante],eax			; se e diferente, entao ele desbloqueou uma letra pelo menos, atualizo o restante			
		cmp dword[restante],0		; se o restante de letras a serem desbloqueadas e zero, o jogo acabou
		je fimdejogo						; fim de jogo		
		jmp jogo

	errouu:	
		mov dword[errou],1
		dec dword[tentativas]		; diminui uma vida	
		cmp dword[tentativas],0	; se vida == 0, entao o cara perdeu o jogo	
		je fimdejogo						; fim de jogo
  jmp jogo						
;-------------------------------------------- LOOP PRINCIPAL ----------------------------------------
	fimdejogo:
	call LIMPA_TELA
	
	cmp dword[restante],0
	je ganhou
	
	;nao ganhou
		call IMPRIME_BONECO
		print msg1,t_msg1

		;cast de 'INT' para 'CHAR'
		mov eax,[tentativas]
		add eax,'0'
		mov dword[aux+0],eax

		print aux,1								; aux contem o numero de tentativas final
		print endl,1							; enter
		print resp,t_resp					; mensagem de reposta final
		print PalavraChave,[tam]	; palavra chave
		print endl,1							; enter
		print msg6,t_msg6					; mensagem de consolo	
		print endl,1							; enter	
		jmp main

	ganhou:
	print msg7,t_msg7
	print endl,1
	
	jmp main
ExitForca
