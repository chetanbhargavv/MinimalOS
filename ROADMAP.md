# MinimalOS Roadmap

This document outlines the planned features and improvements for MinimalOS.

## Version 1.0.0 (Current) ✅

- [x] Multiboot bootloader
- [x] 32-bit protected mode kernel
- [x] Memory management (4MB heap)
- [x] Round-robin task scheduler
- [x] VGA text mode driver
- [x] Basic shell with commands
- [x] Complete documentation

## Version 1.1.0 (Next Release)

### Planned Features

- [ ] **Keyboard Input** (PS/2 driver)
  - Scan code handling
  - Key mapping
  - Interactive shell input
  
- [ ] **Timer Interrupts** (PIT)
  - Programmable Interval Timer setup
  - Interrupt handling
  - System tick counter

- [ ] **Interrupt Descriptor Table (IDT)**
  - IDT setup and configuration
  - Interrupt Service Routines (ISRs)
  - Exception handlers

### Improvements

- [ ] Enhanced memory allocator
  - Free list management
  - Memory defragmentation
  - Better error handling

- [ ] More shell commands
  - `uptime` - Show system uptime
  - `mem` - Display memory usage
  - `tasks` - List running tasks
  - `reboot` - Reboot system

- [ ] Better error messages
- [ ] Code cleanup and refactoring

**Target Release**: Q1 2025

## Version 1.2.0

### Major Features

- [ ] **File System**
  - Simple RAM-based file system
  - File operations (create, read, write, delete)
  - Directory support
  - Basic permissions

- [ ] **Disk I/O**
  - ATA/IDE driver
  - Read/write sectors
  - Disk detection

- [ ] **User Mode**
  - Privilege level separation
  - System calls
  - User space programs

### Enhancements

- [ ] Improved scheduler
  - Priority-based scheduling
  - Better task management
  - Process creation/termination

- [ ] Enhanced VGA driver
  - Cursor support
  - More text modes
  - Basic graphics mode

**Target Release**: Q2 2025

## Version 2.0.0 (Long-term)

### Advanced Features

- [ ] **64-bit Support**
  - Long mode implementation
  - 64-bit kernel
  - Extended memory access

- [ ] **Multi-core Support**
  - SMP (Symmetric Multiprocessing)
  - CPU detection
  - Inter-processor interrupts

- [ ] **Network Stack**
  - Ethernet driver
  - TCP/IP implementation
  - Socket API

- [ ] **Advanced File System**
  - ext2-like file system
  - Journaling
  - Large file support

- [ ] **GUI Support**
  - Framebuffer driver
  - Window manager
  - Basic GUI toolkit

### System Improvements

- [ ] Virtual memory management
- [ ] Demand paging
- [ ] Copy-on-write
- [ ] Memory-mapped files
- [ ] Dynamic linking
- [ ] ELF loader

**Target Release**: 2026

## Future Considerations

### Possible Features

- USB support
- Sound driver
- Power management (ACPI)
- Symmetric multiprocessing
- Virtual machine support
- Container support
- Package manager

### Research Areas

- Microkernel architecture
- Real-time capabilities
- Security hardening
- Performance optimization
- Energy efficiency

## Community Requests

Features requested by the community will be tracked here.

### High Priority

- Keyboard input (multiple requests)
- File system support
- Better documentation

### Medium Priority

- More shell commands
- Debugging tools
- Better error handling

### Low Priority

- GUI support
- Network stack
- USB support

## How to Contribute

Want to help implement these features?

1. Check [CONTRIBUTING.md](CONTRIBUTING.md)
2. Pick a feature from the roadmap
3. Open an issue to discuss implementation
4. Submit a pull request

## Feedback

Have suggestions for the roadmap?

- Open an issue with the `enhancement` label
- Discuss in [GitHub Discussions](https://github.com/chetanbhargavv/MinimalOS/discussions)
- Email: your.email@example.com

---

**Note**: This roadmap is subject to change based on community feedback and development priorities.

Last updated: 2024-11-10
