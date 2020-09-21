; -------------------------------------------
;
;         boot.s: kernel starts here
;
;--------------------------------------------

; Multiboot
MBOOT_HEADER_MAGIC 	equ		0x1BADB002

; 0 represents align by 4KB
MBOOT_PAGE_ALIGN	equ		1 << 0

; include memory info in Multiboot structure
MBOOT_MEM_INFO	   	equ 	1 << 1

; flags
MBOOT_HEADER_FLAGS 	equ 	MBOOT_PAGE_ALIGN | MBOOT_MEM_INFO

; must be 0
MBOOT_CHECKSUM	   	equ 	-(MBOOT_HEADER_MAGIC+MBOOT_HEADER_FLAGS)

[BITS 32]		; compile by 32-bit
section .text	; code seg starts here

dd MBOOT_HEADER_MAGIC	; if GRUB supports the img
dd MBOOT_HEADER_FLAGS	; GRUB options
dd MBOOT_CHECKSUM		; check

[GLOBAL start]			; declare entrance of kernel
[GLOBAL glb_mboot_ptr]	; declare struct multiboot *
[EXTERN kern_entry]		; declare entrance func to c code in kernel

start:
	cli							;
	mov esp, STACK_TOP			; set kernel stack address
	mov ebp, 0					; frame pointer set 0
	and esp, 0FFFFFFF0H			; stack address align 16byte
    mov [glb_mboot_ptr], ebx	; save pointer in ebx to global var
	call kern_entry				; call kernel entry func

stop:
	hlt			;
	jmp stop	;

;---------------------------------------------------------------------------------

section .bss
stack:
	resb 32768	; kernel stack
glb_mboot_ptr:	; global multibooot sturcture pointer
	resb 4 

STACK_TOP equ $-stack-1		; top of kernel stack, $ = current addr
