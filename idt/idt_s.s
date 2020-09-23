[GLOBAL idt_flush]
idt_flush:
    mov eax, [esp+4]    ; save params to eax
    lidt [eax]          ; load to IDTR
    ret
.end:

; define 2 macro to construct interrupt handler func (with error code/not)
; without ec
%macro ISR_NOERRCODE 1
[GLOBAL isr%1]
isr%1:
    cli                 ; close interrupt
    push 0              ; push invalid error code
    push %1             ; push interrupt index
    jmp isr_common_stub
%endmacro

; with ec
%macro ISR_ERRCODE 1
[GLOBAL isr%1]
isr%1:
    cli
    push %1            ; push index 
    jmp isr_common_stub
%endmacro

; define interrupt handler func
ISR_NOERRCODE   0
ISR_NOERRCODE   1
ISR_NOERRCODE   2
ISR_NOERRCODE   3
ISR_NOERRCODE   4
ISR_NOERRCODE   5
ISR_NOERRCODE   6
ISR_NOERRCODE   7
ISR_ERRCODE     8
ISR_NOERRCODE   9
ISR_ERRCODE     10
ISR_ERRCODE     11
ISR_ERRCODE     12
ISR_ERRCODE     13
ISR_ERRCODE     14
ISR_NOERRCODE   15
ISR_NOERRCODE   16
ISR_ERRCODE     17
ISR_NOERRCODE   18
ISR_NOERRCODE   19

; 20~31 intel reserved
ISR_NOERRCODE   20
ISR_NOERRCODE   21
ISR_NOERRCODE   22
ISR_NOERRCODE   23
ISR_NOERRCODE   24
ISR_NOERRCODE   25
ISR_NOERRCODE   26
ISR_NOERRCODE   27
ISR_NOERRCODE   28
ISR_NOERRCODE   29
ISR_NOERRCODE   30
ISR_NOERRCODE   31

; 32~255 user
ISR_NOERRCODE 255

[GLOBAL isr_common_stub]
[EXTERN isr_handler]
; interrupt service
isr_common_stub:
    pusha
    mov ax, ds
    push eax

    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    push esp            ; pointer to pt_regs
    call isr_handler    ; in c code
    add esp, 4          ; clear pushed param

    pop ebx             ; recover ds
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    popa                ; pops all
    add esp, 8          ; clear error code and ISR
    iret
.end: