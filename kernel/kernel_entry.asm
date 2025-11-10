; Kernel entry point - 32-bit for GRUB multiboot
; GRUB loads us in 32-bit protected mode

[BITS 32]
[EXTERN kernel_main]

global _start

section .text
_start:
    ; Setup kernel stack
    mov esp, kernel_stack_top
    
    ; Clear direction flag
    cld

    ; Call C kernel main function
    call kernel_main

    ; Halt if kernel returns
    cli
.hang:
    hlt
    jmp .hang

; Kernel stack (16KB)
section .bss
align 16
kernel_stack_bottom:
    resb 16384
kernel_stack_top:
