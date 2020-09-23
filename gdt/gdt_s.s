[GLOBAL gdt_flush]

gdt_flush:

    mov eax, [esp+4]    ; save params
    lgdt [eax]          ; load to GDTR

    mov ax, 0x10        ; load data segment descriptor
    mov ds, ax          ; update segment registers; I don't know why it crashes here
    mov es, ax          
    mov fs, ax          
    mov gs, ax          
    mov ss, ax
              
    jmp 0x08:.flush     ; 0x08 is segment descriptor to our code
            ; to clear pipeline and serialize cpu
            ; force cpu to update
    ret

.flush:
    ret