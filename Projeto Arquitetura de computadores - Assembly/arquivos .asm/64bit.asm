
; 64-bit "Hello World!" in Linux NASM
 
global _start            ; global entry point export for ld
 
section .text
_start:
 
    ; sys_write(stdout, message, length)
 
    mov    rax, 1        ; sys_write
    mov    rdi, 1        ; stdout
    mov    rsi, message    ; message address
    mov    rdx, length    ; message string length
    syscall
 
    ; sys_exit(return_code)
 
    mov    rax, 60        ; sys_exit
    mov    rdi, 0        ; return 0 (success)
    syscall
 
section .data
    message: db 'Hello, world!',0x0A    ; message and newline
    length:    equ    $-message        ; NASM definition pseudo-instruction
