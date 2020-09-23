#ifndef INCLUDE_GDT_H_
#define INCLUDE_GDT_H_

#include "types.h"

// global descriptor
typedef
struct gdt_entry_t {
    uint16_t limit_low;     // Segment Limit 15~0
    uint16_t base_low;      // Segment Base Address 15~0
    uint8_t base_middle;    // Segment Base Address 23~16
    uint8_t access;         // Segment Existence bit, Segment Priviledge, descriptor type, descriptor child type
    uint8_t granularity;    // other sign, segment limit 19~16
    uint8_t base_high;      // Segment Base Address 31~24
} __attribute__((packed)) gdt_entry_t;

// GDTR
typedef
struct gdt_ptr_t {
    uint16_t limit;     // GDT limit
    uint32_t base;      // global descriptor 32-bit base address
} __attribute__((packed)) gdt_ptr_t;

// init GDT
void init_gdt();

// load GDT to GDTR
extern void gdt_flush(uint32_t);

#endif