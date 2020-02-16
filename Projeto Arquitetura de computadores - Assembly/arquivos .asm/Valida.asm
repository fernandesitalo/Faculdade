section .bss
	strr 	resb 	10
	valor	resd	1
	CODERRO resd 	1
	number 	resb 	10
	
section .data 							
	msg db "Digite a primeira Parcela da Soma: ",endl
	msg_size equ $-msg

; macro	
endl equ 10 


global main
main:
	
	; ---------------- leitura da frase -----------
	mov edx,99
	mov ecx,strr
	mov ebx,0
	mov eax,3
	int 0x80
	
	; o numero já está em strr... vamos Validar
	; eax contem o tamanho da frase digitada
	
	
	; INICIALIZA 	
	mov esi,0
	mov edi,eax
	mov dword[valor],0 
	
	; tamanho da strr
	cmp edi,7 
	ja ERRO2
	
	LOOP:				
		mov cl,[strr + esi]
		sub cl,48
		
		cmp cl,9			; cl e numero ?
		ja ERRO1
		
		mov edx,0 			; p/ multiplicacao
		mov eax,10
		mul ecx				;  edx:eax = edx:eax * ecx
		
		add dword[valor],eax		
		
		inc esi 		 		
		cmp esi,edi 	
		je SAI	
		
	jmp LOOP;
	
	
	
	ERRO1:
		mov dword[CODERRO],1
		jmp SAI
	ERRO2:
		mov dword[CODERRO],2
	SAI:
	
	
; vamo colocar em uma string o que esta em valor
; inicializa 
	
	
	mov ecx,10		; divisor
	mov esi,3
	
	WHILE:
		mov eax,dword[valor]
		mov edx,0
		div ecx
		add edx,48
		mov [number+esi],edx
		
		dec esi	; proxima posicao
		jl PARA	; se eax é 0 para
		
		mov dword[valor],eax
	jmp WHILE
	
	
	PARA:
		; imprime 'number'
	
	mov esi,3
	
	; -------------- impressão da mensagem --------
	mov ebx,1
	mov eax,4
	mov edx,esi
	mov ecx,number
	int 0x80
	

;Finaliza progama
mov ebx,0
mov eax,1
int 0x80
