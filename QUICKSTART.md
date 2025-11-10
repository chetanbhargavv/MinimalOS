# Quick Start Guide

## What You've Got

A complete minimal x86_64 operating system with:
- ✓ 64-bit bootloader with mode transitions
- ✓ Kernel initialization
- ✓ Memory management with paging
- ✓ Task scheduler (round-robin)
- ✓ VGA text mode console
- ✓ Basic shell with commands

## Build & Run (5 minutes)

### Option 1: Linux/WSL (Recommended)

```bash
# Install tools
sudo apt-get update
sudo apt-get install build-essential nasm qemu-system-x86

# Build
make

# Run
make run
```

### Option 2: Windows with WSL

```bash
# Open WSL terminal
wsl

# Follow Option 1 steps above
```

### Option 3: macOS

```bash
# Install tools
brew install nasm qemu

# Build (may need cross-compiler)
make

# Run
make run
```

## What You'll See

When you run the OS, you'll see:

```
=================================
   MinimalOS x86_64 Kernel
=================================

Initializing memory management... [OK]
Initializing scheduler... [OK]
Initializing shell... [OK]

Kernel initialization complete!

Hello, Kernel!

Welcome to MinimalOS Shell!
Type 'help' for available commands.

kernel> help
Available commands:
  help  - Display this help message
  echo  - Echo arguments to screen
  clear - Clear the screen

kernel> echo Hello from MinimalOS!
Hello from MinimalOS!

kernel> 
```

## Project Structure

```
MinimalOS/
├── boot/
│   └── boot.asm          # Bootloader (Real→Protected→Long mode)
├── kernel/
│   ├── kernel_entry.asm  # Kernel entry point (64-bit)
│   ├── kernel.c          # Main kernel initialization
│   ├── screen.c          # VGA text mode driver
│   ├── memory.c          # Memory management
│   ├── scheduler.c       # Task scheduler
│   ├── shell.c           # Basic shell
│   └── string.c          # String utilities
├── include/              # Header files
├── Makefile              # Build system
└── linker.ld             # Linker script
```

## Key Features Explained

### Bootloader (boot/boot.asm)
- Loaded by BIOS at 0x7C00
- Loads kernel from disk
- Transitions: 16-bit Real Mode → 32-bit Protected Mode → 64-bit Long Mode
- Sets up paging and GDT

### Kernel (kernel/)
- **kernel.c**: Initializes all subsystems
- **screen.c**: VGA text output (80x25, 16 colors)
- **memory.c**: Simple bump allocator with 4MB heap
- **scheduler.c**: Round-robin task scheduler (up to 8 tasks)
- **shell.c**: Command interpreter (help, echo, clear)

### Memory Layout
```
0x7C00    - Bootloader
0x1000    - Kernel code
0x200000  - Kernel heap (4MB)
0xB8000   - VGA text buffer
```

## Customization Ideas

### Add a New Shell Command

Edit `kernel/shell.c`:

```c
static void cmd_mycommand(void) {
    screen_println("My custom command!");
}

// Add to shell_run():
shell_prompt();
screen_println("mycommand");
cmd_mycommand();
```

### Change Boot Message

Edit `kernel/kernel.c`:

```c
screen_println("   My Custom OS");
```

### Add More Colors

Edit `kernel/shell.c`:

```c
screen_set_color(COLOR_LIGHT_CYAN, COLOR_BLUE);
screen_println("Colorful text!");
```

## Troubleshooting

### Build fails with "gcc: command not found"
Install GCC: `sudo apt-get install build-essential`

### Build fails with "nasm: command not found"
Install NASM: `sudo apt-get install nasm`

### QEMU shows black screen
- Check that boot signature (0xAA55) is present
- Verify kernel is loaded correctly
- Try: `qemu-system-x86_64 -drive format=raw,file=os-image.bin -serial stdio`

### "No bootable device" in QEMU
- Ensure os-image.bin was created successfully
- Check file size: `ls -lh os-image.bin`

## Next Steps

1. **Read ARCHITECTURE.md** - Understand how everything works
2. **Read BUILDING.md** - Advanced build options
3. **Experiment** - Modify the code and rebuild
4. **Add Features**:
   - Keyboard input (PS/2 driver)
   - Timer interrupt (PIT)
   - More shell commands
   - File system
   - User mode programs

## Resources

- [OSDev Wiki](https://wiki.osdev.org/) - Comprehensive OS development guide
- [Intel 64 Manual](https://software.intel.com/content/www/us/en/develop/articles/intel-sdm.html) - CPU reference
- [NASM Documentation](https://www.nasm.us/docs.php) - Assembly syntax

## Support

This is a minimal educational OS. For questions:
- Check OSDev Wiki forums
- Review the inline code comments
- Study ARCHITECTURE.md for design details

Happy kernel hacking! 🚀
