#!Makefile

C_SOURCES = $(shell find . -name "*.c")
C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))
S_SOURCES = $(shell find . -name "*.s")
S_OBJECTS = $(patsubst %.s, %.o, $(S_SOURCES))

CC = gcc
LD = ld
ASM = nasm

#  -m32: generate 32-bit code
#  -ggdb and -gstabs: for debugging
#  -nostdinc: not include c std lib
#  -fno-bulitin: gcc do not use built-in func
#  -fno-stack-protector: not use stack protector
C_FLAGS = -c -Wall -m32 -ggdb -gstabs+ -nostdinc -fno-builtin -fno-stack-protector -I include

#  -T: use our script
#  -m elf_i386: generate elf in i386 platform
#  -nostdlib: not link c std lib
LD_FLAGS = -T src/kernel.ld -m elf_i386 -nostdlib
ASM_FLAGS = -f elf -g -F stabs

 
all: $(S_OBJECTS) $(C_OBJECTS) link update_image

.c.o:
	@echo compiling c file $< ...
	$(CC) $(C_FLAGS) $< -o $@

.s.o:
	@echo compiling assembly code file $< ...
	$(ASM) $(ASM_FLAGS) $<

# link together into one ELF binary "kernel" using script 'link.ld'
link:
	@echo linking kernel file...
	$(LD) $(LD_FLAGS) $(S_OBJECTS) $(C_OBJECTS) -o toy_kernel

.PHONY:clean
clean:
	$(RM) $(S_OBJECTS) $(C_OBJECTS) toy_kernel

.PHONY: update_image
update_image:
	sudo mount floppy.img /mnt/kernel
	sudo cp toy_kernel /mnt/kernel/toy_kernel
	sleep 1
	sudo umount /mnt/kernel

.PHONY: mount_image
mount_image:
	sudo mount floppy.img /mnt/kernel

.PHONY: umount_image
umount_image:
	sudo umount /mnt/kernel

.PHONY:qemu
qemu:
	qemu -fda floppy.img -boot a

.PHONY:bochs
bochs:
	bochs -f tools/bochsrc.txt

.PHONY:debug
debug:
	qemu -S -s fda floppy.img -boot a &
	sleep 1
	cgdb -x tools/gdbinit




