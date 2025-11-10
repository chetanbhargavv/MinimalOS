# MinimalOS Quick Reference

## Build Commands

```bash
make              # Build kernel
make clean        # Clean build artifacts
make run          # Build and run in QEMU
```

## Run Commands

```bash
# Standard run
qemu-system-i386 -kernel kernel.bin

# With serial output
qemu-system-i386 -kernel kernel.bin -serial stdio

# With debugging
qemu-system-i386 -kernel kernel.bin -s -S
```

## Shell Commands

```
help              # Show available commands
echo [text]       # Echo text to screen
clear             # Clear the screen
```

## File Structure

```
boot/             # Bootloader code
kernel/           # Kernel source files
include/          # Header files
Makefile          # Build system
linker.ld         # Linker script
```

## Key Files

| File | Purpose |
|------|---------|
| `boot/multiboot_header.asm` | Multiboot header |
| `kernel/kernel_entry.asm` | Kernel entry point |
| `kernel/kernel.c` | Main initialization |
| `kernel/screen.c` | VGA driver |
| `kernel/memory.c` | Memory management |
| `kernel/scheduler.c` | Task scheduler |
| `kernel/shell.c` | Shell implementation |

## Memory Layout

```
0x00100000  Kernel code/data
0x00200000  Kernel heap (4MB)
0x000B8000  VGA text buffer
```

## Colors

```c
COLOR_BLACK, COLOR_BLUE, COLOR_GREEN, COLOR_CYAN
COLOR_RED, COLOR_MAGENTA, COLOR_BROWN, COLOR_LIGHT_GREY
COLOR_DARK_GREY, COLOR_LIGHT_BLUE, COLOR_LIGHT_GREEN
COLOR_LIGHT_CYAN, COLOR_LIGHT_RED, COLOR_LIGHT_MAGENTA
COLOR_YELLOW, COLOR_WHITE
```

## Common Functions

```c
// Screen
screen_print(const char* str);
screen_println(const char* str);
screen_putchar(char c);
screen_set_color(uint8_t fg, uint8_t bg);
screen_clear(void);

// Memory
void* kmalloc(size_t size);
void kfree(void* ptr);
void* memset(void* dest, int val, size_t len);
void* memcpy(void* dest, const void* src, size_t len);

// String
size_t strlen(const char* str);
int strcmp(const char* s1, const char* s2);
char* strcpy(char* dest, const char* src);
```

## Debugging

```bash
# Run with GDB
qemu-system-i386 -kernel kernel.bin -s -S

# In another terminal
gdb kernel.bin
(gdb) target remote localhost:1234
(gdb) break kernel_main
(gdb) continue
```

## Troubleshooting

| Problem | Solution |
|---------|----------|
| Build fails | `sudo apt-get install gcc-multilib` |
| NASM not found | `sudo apt-get install nasm` |
| QEMU not found | `sudo apt-get install qemu-system-x86` |
| Black screen | Try `-serial stdio` flag |

## Git Commands

```bash
git init
git add .
git commit -m "Initial commit"
git remote add origin https://github.com/user/repo.git
git push -u origin main
```

## Documentation

- **README.md** - Getting started
- **INSTALL.md** - Installation guide
- **ARCHITECTURE.md** - Technical details
- **CONTRIBUTING.md** - How to contribute
- **FAQ.md** - Common questions

## Links

- OSDev Wiki: https://wiki.osdev.org/
- Intel Manual: https://software.intel.com/sdm
- Multiboot Spec: https://www.gnu.org/software/grub/manual/multiboot/
- NASM Docs: https://www.nasm.us/docs.php

---

**Quick Start**: `make && make run`
