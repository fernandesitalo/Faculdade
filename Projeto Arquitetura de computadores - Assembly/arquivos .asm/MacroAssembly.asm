
; PILHA TEM 64 BITS

; registradores de dados: ax,bx,dx,cx
; eax,ecx,edx,ebx sao registradores nas versoes 32 bits
; rax,rcx,rdx,rbx sao registradores nas versoes de 64 bits
; por isso usados os registradores rax,rcx... para empilhar e desempilhar..
; a pilha e de 64 bits , logo precisamos de resgistradores de 64 bits


%macro print 2   ; (endereço_msg, tam_msg)
	push rcx ; salvar o registrador cx de 64 bits 
	push rdx ; ''
	push rbx ; ''
	push rax ; ''
	
	mov ecx,%1
	mov edx,%2
	mov ebx,1
	mov eax,4
	int 0x80
	
	pop rax	; coloca em ax o que esta no topo da pilha
	pop rbx	; coloca em bx o que esta no topo da pilha
	pop rdx	; ''
	pop rcx	; ''
%endmacro

%macro Exit 0
	mov ebx,0
	mov eax,1
	int 0x80
%endmacro



section .bss
	
	
section .data
	msg db "E NOIS QUE VOA!",10
	tmsg equ $-msg

global main
main:

print msg,tmsg
Exit
