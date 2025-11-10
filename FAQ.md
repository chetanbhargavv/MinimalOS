# Frequently Asked Questions (FAQ)

## General Questions

### What is MinimalOS?

MinimalOS is a minimal x86 operating system kernel built from scratch as an educational project. It demonstrates fundamental OS concepts including bootloading, memory management, multitasking, and basic I/O.

### Is this a real operating system?

Yes and no. It's a real kernel that boots and runs, but it's minimal and designed for education rather than production use. It lacks many features of modern operating systems like file systems, networking, and user applications.

### What can I do with MinimalOS?

- Learn how operating systems work
- Understand low-level programming
- Experiment with kernel development
- Use as a base for your own OS project
- Study x86 architecture and assembly

### Is MinimalOS suitable for production use?

No. MinimalOS is an educational project and lacks many features required for production systems:
- No file system
- No networking
- No user mode
- No security features
- Limited hardware support

## Technical Questions

### What architecture does MinimalOS support?

Currently, MinimalOS supports x86 (32-bit protected mode). It runs on:
- x86 processors (Intel/AMD)
- x86_64 processors in 32-bit compatibility mode
- QEMU emulator
- VirtualBox
- Real hardware (with limitations)

### Why 32-bit instead of 64-bit?

32-bit mode is simpler to implement and understand for educational purposes. The concepts learned apply to 64-bit development as well. A 64-bit version may be added in the future.

### Does it support UEFI?

No, MinimalOS uses the Multiboot specification which works with GRUB. UEFI support could be added but would increase complexity.

### Can I run this on real hardware?

Technically yes, but it's not recommended:
- Limited hardware support
- No drivers for most devices
- Could potentially damage hardware if bugs exist
- Better to use QEMU or VirtualBox

## Building and Running

### What do I need to build MinimalOS?

- GCC compiler (with 32-bit support)
- NASM assembler
- GNU Make
- QEMU (for testing)

See [INSTALL.md](INSTALL.md) for detailed instructions.

### Why does the build fail with "unrecognized option '-m32'"?

You need 32-bit compilation support:
```bash
sudo apt-get install gcc-multilib
```

### How do I run MinimalOS?

```bash
make run
```

Or manually:
```bash
qemu-system-i386 -kernel kernel.bin
```

### Can I run it in VirtualBox?

Yes, but you need to create a bootable ISO first (requires GRUB):
```bash
# Install grub-mkrescue
sudo apt-get install grub-pc-bin xorriso

# Create ISO
mkdir -p isodir/boot/grub
cp kernel.bin isodir/boot/
cp boot/grub.cfg isodir/boot/grub/
grub-mkrescue -o minimalos.iso isodir

# Run in VirtualBox
# Create new VM, attach minimalos.iso as CD-ROM, boot
```

### Why does QEMU show a black screen?

Common causes:
1. Kernel didn't build correctly - check `kernel.bin` exists
2. Multiboot header is incorrect - rebuild with `make clean && make`
3. QEMU version issue - try `qemu-system-i386 -kernel kernel.bin -serial stdio`

## Development Questions

### How do I add a new feature?

1. Read the code to understand the structure
2. Implement your feature
3. Test thoroughly
4. Update documentation
5. Submit a pull request

See [CONTRIBUTING.md](CONTRIBUTING.md) for details.

### Can I use this code in my project?

Yes! MinimalOS is licensed under MIT License. You can:
- Use it in personal projects
- Use it in commercial projects
- Modify and distribute
- Just keep the license notice

### How do I add keyboard input?

Keyboard input requires implementing a PS/2 keyboard driver. This involves:
1. Setting up interrupt handling (IDT)
2. Configuring the keyboard controller
3. Reading scan codes from port 0x60
4. Converting scan codes to characters

This is a great next feature to implement!

### How do I add a file system?

File system implementation is complex. Start with:
1. Design a simple file system format
2. Implement disk I/O (ATA/IDE driver)
3. Create file operations (open, read, write, close)
4. Add directory support

Consider starting with a RAM-based file system first.

## Troubleshooting

### Build fails with linker errors

Ensure you're using the correct linker flags:
```makefile
LDFLAGS = -T linker.ld -nostdlib -melf_i386
```

### Kernel crashes immediately

Common causes:
- Stack overflow - increase stack size in `kernel_entry.asm`
- Invalid memory access - check pointer arithmetic
- Uninitialized variables - ensure all variables are initialized

Use QEMU debugging:
```bash
qemu-system-i386 -kernel kernel.bin -d int,cpu_reset -no-reboot
```

### "Triple fault" error

This usually means:
- Invalid page table setup
- Incorrect GDT/IDT configuration
- Stack corruption
- Invalid instruction execution

Check the boot process and memory setup carefully.

### How do I debug the kernel?

Use GDB with QEMU:
```bash
# Terminal 1
qemu-system-i386 -kernel kernel.bin -s -S

# Terminal 2
gdb kernel.bin
(gdb) target remote localhost:1234
(gdb) break kernel_main
(gdb) continue
```

## Learning Resources

### Where can I learn more about OS development?

- [OSDev Wiki](https://wiki.osdev.org/) - Comprehensive resource
- [Intel Software Developer Manuals](https://software.intel.com/sdm) - CPU reference
- [Multiboot Specification](https://www.gnu.org/software/grub/manual/multiboot/)
- [NASM Documentation](https://www.nasm.us/docs.php)

### What should I learn before OS development?

Recommended knowledge:
- C programming (pointers, memory management)
- Assembly language (x86)
- Computer architecture
- Data structures and algorithms
- Basic understanding of how computers work

### What books do you recommend?

- "Operating Systems: Three Easy Pieces" by Remzi H. Arpaci-Dusseau
- "Operating System Concepts" by Silberschatz, Galvin, and Gagne
- "Modern Operating Systems" by Andrew S. Tanenbaum
- "The Art of Assembly Language" by Randall Hyde

### Are there similar projects?

Yes, many educational OS projects exist:
- [ToaruOS](https://github.com/klange/toaruos)
- [SerenityOS](https://github.com/SerenityOS/serenity)
- [xv6](https://github.com/mit-pdos/xv6-public)
- [MenuetOS](http://menuetos.net/)

## Contributing

### How can I contribute?

See [CONTRIBUTING.md](CONTRIBUTING.md) for detailed guidelines. Easy contributions include:
- Documentation improvements
- Bug fixes
- Adding comments
- Testing on different platforms

### I found a bug, what should I do?

1. Check if it's already reported in [Issues](https://github.com/yourusername/MinimalOS/issues)
2. If not, create a new issue with:
   - Clear description
   - Steps to reproduce
   - Expected vs actual behavior
   - System information

### Can I add my own features?

Absolutely! Fork the repository, implement your feature, and submit a pull request. Make sure to:
- Follow coding standards
- Add documentation
- Test thoroughly
- Update CHANGELOG.md

## License and Legal

### What license is MinimalOS under?

MIT License - very permissive. You can use, modify, and distribute freely.

### Can I use this for commercial purposes?

Yes, the MIT License allows commercial use.

### Do I need to credit MinimalOS?

The MIT License requires you to include the license notice, but you don't need to actively credit the project (though it's appreciated!).

## Still Have Questions?

- Check the [documentation](README.md)
- Search [existing issues](https://github.com/chetanbhargavv/MinimalOS/issues)
- Ask in [Discussions](https://github.com/chetanbhargavv/MinimalOS/discussions)
- Email: your.email@example.com

---

**Didn't find your answer?** [Open an issue](https://github.com/chetanbhargavv/MinimalOS/issues/new) and we'll add it to this FAQ!
