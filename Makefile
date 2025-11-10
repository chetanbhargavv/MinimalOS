# Makefile for MinimalOS with GRUB (32-bit for simplicity)

ASM = nasm
CC = gcc
LD = ld

# 32-bit flags for compatibility
ASMFLAGS = -f elf32
CFLAGS = -m32 -ffreestanding -fno-pie -fno-stack-protector -nostdlib -nostdinc \
         -I./include -O2 -Wall -Wextra
LDFLAGS = -T linker.ld -nostdlib -melf_i386

# Source files
KERNEL_OBJS = boot/multiboot_header.o kernel/kernel_entry.o kernel/kernel.o \
              kernel/screen.o kernel/memory.o kernel/scheduler.o kernel/shell.o \
              kernel/string.o

KERNEL_BIN = kernel.bin

all: $(KERNEL_BIN)
	@echo "Kernel built: $(KERNEL_BIN)"
	@echo "Run with: qemu-system-i386 -kernel $(KERNEL_BIN)"

$(KERNEL_BIN): $(KERNEL_OBJS)
	$(LD) $(LDFLAGS) -o $(KERNEL_BIN) $(KERNEL_OBJS)

boot/multiboot_header.o: boot/multiboot_header.asm
	$(ASM) $(ASMFLAGS) boot/multiboot_header.asm -o boot/multiboot_header.o

kernel/kernel_entry.o: kernel/kernel_entry.asm
	$(ASM) $(ASMFLAGS) kernel/kernel_entry.asm -o kernel/kernel_entry.o

kernel/%.o: kernel/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f boot/*.o kernel/*.o $(KERNEL_BIN)

run: $(KERNEL_BIN)
	qemu-system-i386 -kernel $(KERNEL_BIN)

.PHONY: all clean run
