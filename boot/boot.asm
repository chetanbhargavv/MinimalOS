; Minimal working bootloader for x86_64
[BITS 16]
[ORG 0x7C00]

start:
    cli
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00
    
    ; Load kernel (20 sectors starting at sector 2)
    mov bx, 0x1000
    mov ah, 0x02
    mov al, 20
    mov ch, 0
    mov dh, 0
    mov cl, 2
    mov dl, 0x80
    int 0x13
    
    ; Enable A20
    in al, 0x92
    or al, 2
    out 0x92, al
    
    ; Load GDT
    lgdt [gdt_desc]
    
    ; Enter protected mode
    mov eax, cr0
    or al, 1
    mov cr0, eax
    
    jmp 0x08:protected_mode

[BITS 32]
protected_mode:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov esp, 0x90000
    
    ; Setup paging at 0x1000 (page tables)
    mov edi, 0x1000
    mov cr3, edi
    xor eax, eax
    mov ecx, 4096
    rep stosd
    mov edi, cr3
    
    ; PML4[0] -> 0x2000
    mov dword [edi], 0x2003
    add edi, 0x1000
    ; PDPT[0] -> 0x3000
    mov dword [edi], 0x3003
    add edi, 0x1000
    ; PD[0] = 2MB page
    mov dword [edi], 0x83
    
    ; Enable PAE
    mov eax, cr4
    or eax, 0x20
    mov cr4, eax
    
    ; Enable long mode (set EFER.LME)
    mov ecx, 0xC0000080
    rdmsr
    or eax, 0x100
    wrmsr
    
    ; Enable paging
    mov eax, cr0
    or eax, 0x80000000
    mov cr0, eax
    
    ; Jump to 64-bit code
    lgdt [gdt64_desc]
    jmp 0x08:long_mode

[BITS 64]
long_mode:
    cli
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    
    ; Jump to kernel at 0x100000 (1MB)
    mov rax, 0x100000
    jmp rax

; 32-bit GDT
align 8
gdt_start:
    dq 0                        ; Null
    dq 0x00CF9A000000FFFF      ; Code
    dq 0x00CF92000000FFFF      ; Data
gdt_end:

gdt_desc:
    dw gdt_end - gdt_start - 1
    dd gdt_start

; 64-bit GDT
align 8
gdt64_start:
    dq 0                        ; Null
    dq 0x00209A0000000000      ; Code
    dq 0x0000920000000000      ; Data
gdt64_end:

gdt64_desc:
    dw gdt64_end - gdt64_start - 1
    dd gdt64_start

times 510-($-$$) db 0
dw 0xAA55
