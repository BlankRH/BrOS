#ifndef INCLUDE_IDT_H_
#define INCLUDE_IDT_H_

#include "types.h"

void init_idt();

typedef
struct idt_entry_t {
    uint16_t base_lo;
    uint16_t sel;
    uint8_t always0;
    uint8_t flags;
    uint16_t base_hi;
}__attribute__((packde)) idt_entry_t;

// IDTR
typedef
struct idt_ptr_t {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idt_ptr_t;

// regidter
typedef
struct pt_regs_t {
    uint32_t ds;
    uint32_t edi;
    uint32_t esi;
    uint32_t ebp;
    uint32_t esp;
    uint32_t eax;
    uint32_t ebx;
    uint32_t ecx;
    uint32_t edx;
    uint32_t int_no;
    uint32_t err_code;
    uint32_t eip;
    uint32_t cs;
    uint32_t eflags;
    uint32_t useresp;
    uint32_t ss;
} pt_regs;

// define interrupt handler func pointer
typedef void (*interrupt_handler_t)(pt_regs *);

// interrupt handler
void register_interrupt_handler(uint8_t n, interrupt_handler_t h);

// call interrupt handler func
void isr_handler(pt_regs *regs);

// interrupt handler func 0-19 belongs to CPU error
// ISR:intterupt service routine
void isr0();    // 0 #DE devide by 0
void isr1();    // 1 #DB debugging error
void isr2();    // 2 NMI
void isr3();    // 3 BP breakpoint
void isr4();    // 4 #OF overflow
void isr5();    // 5 #BR reference to arr out of bound
void isr6();    // 6 #UD invalid or undefined operation code
void isr7();    // 7 #NM device not avaliable
void isr8();    // 8 #DF double faliure (error code)
void isr9();    // 9 
void isr10();   // 10 #TS invalid TSS (error code)
void isr11();   // 11 #NP segment not exist (error code)
void isr12();   // 12 #ss stack error (error code)
void isr13();   // 13 #GP routine protection (error code)
void isr14();   // 14 #PF Page Fail (error code)
void isr15();   // 15 CPU reservation
void isr16();   // #MF float point module fail
void isr17();   // 17 #AC alignment check
void isr18();   // 18 #MC machine check
void isr19();   // 19 #XM SIMD float point error

// 20-31 Intel reserved
void isr20();
void isr21();
void isr22();
void isr23();
void isr24();
void isr25();
void isr26();
void isr27();
void isr28();
void isr29();
void isr30();
void isr31();

// 30-255 user define
void isr255();

#endif