# MinimalOS

A minimal x86 operating system kernel built from scratch in C and Assembly, featuring memory management, multitasking, and a basic shell.

![Build Status](https://github.com/chetanbhargavv/MinimalOS/workflows/Build%20and%20Test/badge.svg)
![License](https://img.shields.io/github/license/chetanbhargavv/MinimalOS)
![GitHub release](https://img.shields.io/github/v/release/chetanbhargavv/MinimalOS)

![MinimalOS Screenshot](screenshot.png)

## Features

- 🚀 **Multiboot-compliant bootloader** - GRUB compatible
- 💾 **Memory Management** - 4MB heap with dynamic allocation (kmalloc/kfree)
- ⚡ **Task Scheduler** - Round-robin scheduling supporting up to 8 concurrent tasks
- 🖥️ **VGA Text Mode Driver** - 80x25 display with 16-color support
- 🐚 **Interactive Shell** - Command-line interface with built-in commands
- 📝 **Well-documented code** - Every function explained with comments

## Quick Start

### Prerequisites

- GCC (cross-compiler recommended)
- NASM assembler
- GNU Make
- QEMU (for testing)

**Ubuntu/Debian:**
```bash
sudo apt-get install build-essential nasm qemu-system-x86
```

**macOS:**
```bash
brew install nasm qemu i686-elf-gcc
```

**Windows:**
Use WSL (Windows Subsystem for Linux) and follow Ubuntu instructions.

### Building

```bash
# Clone the repository
git clone https://github.com/chetanbhargavv/MinimalOS.git
cd MinimalOS

# Build the kernel
make

# Run in QEMU
make run
```

That's it! You should see the kernel boot and display "Hello, Kernel!"

## Project Structure

```
MinimalOS/
├── boot/
│   ├── multiboot_header.asm    # Multiboot header for GRUB
│   └── grub.cfg                # GRUB configuration
├── kernel/
│   ├── kernel_entry.asm        # Kernel entry point (32-bit)
│   ├── kernel.c                # Main kernel initialization
│   ├── screen.c                # VGA text mode driver
│   ├── memory.c                # Memory management
│   ├── scheduler.c             # Task scheduler
│   ├── shell.c                 # Shell implementation
│   └── string.c                # String utilities
├── include/
│   ├── types.h                 # Type definitions
│   ├── screen.h                # Screen driver interface
│   ├── memory.h                # Memory management interface
│   ├── scheduler.h             # Scheduler interface
│   ├── shell.h                 # Shell interface
│   └── string.h                # String utilities interface
├── Makefile                    # Build system
├── linker.ld                   # Linker script
└── README.md                   # This file
```

## Shell Commands

Once the kernel boots, you can use these commands:

- `help` - Display available commands
- `echo [text]` - Echo text to the screen
- `clear` - Clear the screen

## Architecture

### Boot Process

1. **GRUB Bootloader** loads the kernel using Multiboot specification
2. **Kernel Entry** (`kernel_entry.asm`) sets up the stack and calls `kernel_main()`
3. **Kernel Initialization** (`kernel.c`) initializes all subsystems:
   - VGA screen driver
   - Memory management
   - Task scheduler
   - Shell
4. **Shell** starts and displays the prompt

### Memory Layout

```
0x00000000 - 0x000FFFFF  Reserved (BIOS, etc.)
0x00100000 - 0x001FFFFF  Kernel code and data
0x00200000 - 0x005FFFFF  Kernel heap (4MB)
0x000B8000 - 0x000B8FA0  VGA text buffer
```

### Components

#### VGA Driver (`screen.c`)
- 80x25 text mode
- 16 foreground colors, 8 background colors
- Automatic scrolling
- Character and string output functions

#### Memory Manager (`memory.c`)
- Simple bump allocator
- 4MB heap starting at 0x200000
- `kmalloc()` and `kfree()` functions
- Memory utilities: `memset()`, `memcpy()`

#### Task Scheduler (`scheduler.c`)
- Round-robin scheduling algorithm
- Up to 8 concurrent tasks
- Task states: READY, RUNNING, BLOCKED
- 8KB stack per task

#### Shell (`shell.c`)
- Command-line interface
- Command parsing and execution
- Built-in commands
- Colored prompt

## Building from Source

### Detailed Build Instructions

1. **Install Dependencies**
   ```bash
   # Ubuntu/Debian
   sudo apt-get update
   sudo apt-get install build-essential nasm qemu-system-x86
   
   # Arch Linux
   sudo pacman -S base-devel nasm qemu
   ```

2. **Build the Kernel**
   ```bash
   make clean  # Clean previous builds
   make        # Build kernel
   ```

3. **Run in QEMU**
   ```bash
   make run    # Run with QEMU
   ```

### Build Targets

- `make` or `make all` - Build the kernel
- `make clean` - Remove build artifacts
- `make run` - Build and run in QEMU
- `make run-kernel` - Run kernel directly (faster)

## Development

### Adding a New Shell Command

1. Edit `kernel/shell.c`
2. Add your command function:
   ```c
   static void cmd_mycommand(void) {
       screen_println("My custom command!");
   }
   ```
3. Call it in `shell_run()`:
   ```c
   shell_prompt();
   screen_println("mycommand");
   cmd_mycommand();
   ```

### Modifying Colors

Edit `kernel/kernel.c` to change boot message colors:
```c
screen_set_color(COLOR_LIGHT_CYAN, COLOR_BLACK);
screen_println("My Custom OS");
```

Available colors: `COLOR_BLACK`, `COLOR_BLUE`, `COLOR_GREEN`, `COLOR_CYAN`, `COLOR_RED`, `COLOR_MAGENTA`, `COLOR_BROWN`, `COLOR_LIGHT_GREY`, `COLOR_DARK_GREY`, `COLOR_LIGHT_BLUE`, `COLOR_LIGHT_GREEN`, `COLOR_LIGHT_CYAN`, `COLOR_LIGHT_RED`, `COLOR_LIGHT_MAGENTA`, `COLOR_YELLOW`, `COLOR_WHITE`

## Testing

### Running in QEMU

```bash
# Standard run
qemu-system-i386 -kernel kernel.bin

# With serial output
qemu-system-i386 -kernel kernel.bin -serial stdio

# With more memory
qemu-system-i386 -kernel kernel.bin -m 128M
```

### Debugging

```bash
# Run with GDB support
qemu-system-i386 -kernel kernel.bin -s -S

# In another terminal
gdb kernel.bin
(gdb) target remote localhost:1234
(gdb) continue
```

## Troubleshooting

### Build Errors

**Error: `nasm: command not found`**
```bash
sudo apt-get install nasm
```

**Error: `gcc: error: unrecognized command line option '-m32'`**
```bash
sudo apt-get install gcc-multilib
```

### Runtime Issues

**QEMU shows black screen**
- Ensure kernel.bin was created successfully
- Check that multiboot header is correct
- Try: `qemu-system-i386 -kernel kernel.bin -serial stdio`

**Kernel crashes or reboots**
- Check for stack overflow
- Verify memory addresses are correct
- Use QEMU debugging: `qemu-system-i386 -kernel kernel.bin -d int,cpu_reset`

## Contributing

Contributions are welcome! Here are some ideas:

- [ ] Add keyboard input support (PS/2 driver)
- [ ] Implement timer interrupts (PIT)
- [ ] Add more shell commands
- [ ] Create a simple file system
- [ ] Implement user mode and system calls
- [ ] Add network support
- [ ] Multi-core support

### How to Contribute

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## Learning Resources

- [OSDev Wiki](https://wiki.osdev.org/) - Comprehensive OS development guide
- [Intel 64 and IA-32 Architectures Software Developer Manuals](https://software.intel.com/content/www/us/en/develop/articles/intel-sdm.html)
- [Multiboot Specification](https://www.gnu.org/software/grub/manual/multiboot/multiboot.html)
- [NASM Documentation](https://www.nasm.us/docs.php)

## Technical Details

### System Requirements

- x86 or x86_64 processor
- At least 64MB RAM (for QEMU)
- VGA-compatible display

### Specifications

- **Architecture**: x86 (32-bit protected mode)
- **Boot Protocol**: Multiboot 1
- **Language**: C (kernel) + Assembly (boot code)
- **Compiler**: GCC with `-m32 -ffreestanding`
- **Assembler**: NASM
- **Linker**: GNU ld

### Code Statistics

- **Total Lines**: ~2,000
- **Source Files**: 8 (C + Assembly)
- **Header Files**: 6
- **Documentation**: 10+ files

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Inspired by the OSDev community
- Built as an educational project to understand OS fundamentals
- Thanks to all contributors and testers

## Author

**Your Name**
- GitHub: [@chetanbhargavv](https://github.com/chetanbhargavv)
- Email: your.email@example.com

## Changelog

### Version 1.0.0 (2024-11-10)
- Initial release
- Multiboot bootloader
- Memory management with 4MB heap
- Round-robin task scheduler
- VGA text mode driver
- Interactive shell with basic commands
- Complete documentation

---

**Star ⭐ this repository if you found it helpful!**

[![GitHub stars](https://img.shields.io/github/stars/chetanbhargavv/MinimalOS?style=social)](https://github.com/chetanbhargavv/MinimalOS)

For questions or issues, please [open an issue](https://github.com/chetanbhargavv/MinimalOS/issues).
