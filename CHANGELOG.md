# Changelog

All notable changes to MinimalOS will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.0] - 2024-11-10

### Added
- Initial release of MinimalOS
- Multiboot-compliant bootloader for GRUB compatibility
- 32-bit protected mode kernel
- Memory management system with 4MB heap
  - `kmalloc()` for dynamic memory allocation
  - `kfree()` for memory deallocation
  - `memset()` and `memcpy()` utilities
- Round-robin task scheduler
  - Support for up to 8 concurrent tasks
  - Task states: READY, RUNNING, BLOCKED
  - 8KB stack per task
- VGA text mode driver
  - 80x25 character display
  - 16 foreground colors
  - 8 background colors
  - Automatic scrolling
- Interactive shell with commands:
  - `help` - Display available commands
  - `echo` - Echo text to screen
  - `clear` - Clear the screen
- String utility functions
  - `strlen()`, `strcmp()`, `strncmp()`
  - `strcpy()`, `strncpy()`
- Comprehensive documentation
  - README.md with quick start guide
  - ARCHITECTURE.md with technical details
  - INSTALL.md with platform-specific instructions
  - CONTRIBUTING.md with contribution guidelines
- Build system with Makefile
  - `make` - Build kernel
  - `make clean` - Clean build artifacts
  - `make run` - Run in QEMU
- MIT License

### Technical Details
- **Architecture**: x86 (32-bit protected mode)
- **Boot Protocol**: Multiboot 1
- **Language**: C and Assembly (NASM)
- **Compiler**: GCC with `-m32 -ffreestanding`
- **Total Lines of Code**: ~2,000

## [Unreleased]

### Planned Features
- Keyboard input support (PS/2 driver)
- Timer interrupts (PIT)
- Interrupt Descriptor Table (IDT)
- More shell commands
- File system support
- User mode and system calls
- Network stack
- Multi-core support

---

## Version History

- **1.0.0** (2024-11-10) - Initial release

## How to Update

To update to the latest version:

```bash
git pull origin main
make clean
make
```

## Breaking Changes

None yet - this is the initial release.

## Migration Guide

Not applicable for initial release.

---

For more details on each release, see the [GitHub Releases](https://github.com/yourusername/MinimalOS/releases) page.
