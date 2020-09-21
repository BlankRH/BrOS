#ifndef INCLUDE_MULTIBOOT_H_
#define INCLUDE_MULTIBOOT_H_

#include "types.h"

typedef
struct multiboot_t {
    uint32_t flags;     // version
    /**
     * Avaliable memory
     * 
     */
    uint32_t mem_lower; // starts from 0; maximum = 640K
    uint32_t mem_upper; // starts from 1M; maximum = max - 1M

    uint32_t boot_device;   // which BIOS to load OS from
    uint32_t cmdline;       // kernel cmdline
    uint32_t mods_count;    // boot module list
    uint32_t mods_addr;

    /**
     * section head table of kernel image in ELF, including size, number, and name string
     */
    uint32_t num;
    uint32_t size;
    uint32_t addr;
    uint32_t shndx;

    /**
     * mmap_addr: buffer address
     * mmap_length: buffer size
     * buffer is composed of one or more mmap_entry_t
     */
    uint32_t mmap_length;
    uint32_t mmap_addr;
    
    uint32_t drives_length; // size of first driver structure
    uint32_t drives_addr;   // address of first driver structure
    uint32_t config_table;  // ROM config
    uint32_t boot_loader_name;
    uint32_t apm_table;     // APM table
    uint32_t vbe_control_info;
    uint32_t vbe_mode_info;
    uint32_t vbe_mode;
    uint32_t vbe_interface_seg;
    uint32_t vbe_interface_off;
    uint32_t vbe_interface_len;
} __attribute__((packed)) multiboot_t;

/**
 * size is size of the structure in bytes
 * base_addr_low: low 32-bit of starting address
 * base_addr_high: high 32-bit of --
 * length_low: low 32-bit of memory
 * length_high: high --
 * type: type of corresponding address; 1 = avaliable RAM, others = reserved
 */
typedef
struct mmap_entry_t {
    uint32_t size;              // size does not include the size of itself
    uint32_t base_addr_low;
    uint32_t base_addr_high;
    uint32_t length_low;
    uint32_t length_high;
    uint32_t type;
} __attribute__((packed)) mmap_entry_t;

extern multiboot_t *glb_mboot_ptr;

#endif