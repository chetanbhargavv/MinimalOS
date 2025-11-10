# MinimalOS Documentation Index

## 🎯 New to the Project? Start Here!

**[START_HERE.md](START_HERE.md)** - Your entry point to MinimalOS
- Quick overview
- 3-step quick start
- Project structure
- What you'll see

## 📖 Documentation by Purpose

### Getting Started (Read First)
1. **[START_HERE.md](START_HERE.md)** - Begin your journey
2. **[QUICKSTART.md](QUICKSTART.md)** - Get running in 5 minutes
3. **[README.md](README.md)** - Project overview and features

### Understanding the System
4. **[OVERVIEW.txt](OVERVIEW.txt)** - Visual project overview
5. **[ARCHITECTURE.md](ARCHITECTURE.md)** - Deep dive into system design
6. **[BOOT_PROCESS.txt](BOOT_PROCESS.txt)** - Boot sequence diagrams

### Building and Testing
7. **[BUILDING.md](BUILDING.md)** - Detailed build instructions
8. **[TEST_INSTRUCTIONS.md](TEST_INSTRUCTIONS.md)** - Testing and debugging
9. **[Makefile](Makefile)** - Build system

### Reference
10. **[PROJECT_SUMMARY.md](PROJECT_SUMMARY.md)** - Complete feature list
11. **[CHECKLIST.md](CHECKLIST.md)** - Requirements verification
12. **[.gitignore](.gitignore)** - Git configuration

## 📂 Source Code Files

### Bootloader
- **[boot/boot.asm](boot/boot.asm)** - 512-byte bootloader
  - Real Mode initialization
  - Disk loading
  - Mode transitions (16→32→64 bit)
  - Paging setup

### Kernel Assembly
- **[kernel/kernel_entry.asm](kernel/kernel_entry.asm)** - 64-bit kernel entry
  - Stack setup
  - Call to C code

### Kernel C Code
- **[kernel/kernel.c](kernel/kernel.c)** - Main initialization
  - Subsystem startup
  - Boot messages
  
- **[kernel/screen.c](kernel/screen.c)** - VGA text mode driver
  - Character output
  - Color management
  - Scrolling
  
- **[kernel/memory.c](kernel/memory.c)** - Memory management
  - Heap allocator
  - Memory utilities
  
- **[kernel/scheduler.c](kernel/scheduler.c)** - Task scheduler
  - Round-robin scheduling
  - Task creation
  
- **[kernel/shell.c](kernel/shell.c)** - Shell implementation
  - Command processing
  - Built-in commands
  
- **[kernel/string.c](kernel/string.c)** - String utilities
  - String operations

### Header Files
- **[include/types.h](include/types.h)** - Type definitions
- **[include/screen.h](include/screen.h)** - Screen interface
- **[include/memory.h](include/memory.h)** - Memory interface
- **[include/scheduler.h](include/scheduler.h)** - Scheduler interface
- **[include/shell.h](include/shell.h)** - Shell interface
- **[include/string.h](include/string.h)** - String interface

### Build System
- **[Makefile](Makefile)** - Unix/Linux build
- **[linker.ld](linker.ld)** - Linker script
- **[build.bat](build.bat)** - Windows build script

## 📚 Documentation by Topic

### Architecture & Design
- [ARCHITECTURE.md](ARCHITECTURE.md) - System architecture
- [BOOT_PROCESS.txt](BOOT_PROCESS.txt) - Boot flow
- [OVERVIEW.txt](OVERVIEW.txt) - Visual overview

### Building & Running
- [BUILDING.md](BUILDING.md) - Build instructions
- [QUICKSTART.md](QUICKSTART.md) - Quick start
- [Makefile](Makefile) - Build system

### Testing & Debugging
- [TEST_INSTRUCTIONS.md](TEST_INSTRUCTIONS.md) - Testing guide
- [CHECKLIST.md](CHECKLIST.md) - Verification checklist

### Reference & Summary
- [PROJECT_SUMMARY.md](PROJECT_SUMMARY.md) - Complete summary
- [README.md](README.md) - Project overview
- [START_HERE.md](START_HERE.md) - Getting started

## 🎓 Learning Paths

### Path 1: Quick Start (30 minutes)
1. [START_HERE.md](START_HERE.md) - Overview
2. [QUICKSTART.md](QUICKSTART.md) - Build and run
3. [README.md](README.md) - Features
4. Experiment with the code!

### Path 2: Understanding (2 hours)
1. [START_HERE.md](START_HERE.md) - Overview
2. [OVERVIEW.txt](OVERVIEW.txt) - Visual guide
3. [ARCHITECTURE.md](ARCHITECTURE.md) - Deep dive
4. [BOOT_PROCESS.txt](BOOT_PROCESS.txt) - Boot sequence
5. Read source code with comments

### Path 3: Development (4+ hours)
1. Complete Path 2
2. [BUILDING.md](BUILDING.md) - Build details
3. [TEST_INSTRUCTIONS.md](TEST_INSTRUCTIONS.md) - Testing
4. Modify and extend the code
5. Add new features

## 🔍 Quick Reference

### Commands
```bash
make              # Build the OS
make clean        # Clean build artifacts
make run          # Build and run in QEMU
```

### Shell Commands
```
help              # Show available commands
echo [text]       # Echo text to screen
clear             # Clear the screen
```

### Memory Layout
```
0x7C00    - Bootloader
0x1000    - Kernel code
0x100000  - Kernel stack
0x200000  - Kernel heap (4MB)
0xB8000   - VGA text buffer
```

### Key Files by Function

**Want to understand boot process?**
→ [boot/boot.asm](boot/boot.asm), [BOOT_PROCESS.txt](BOOT_PROCESS.txt)

**Want to understand kernel initialization?**
→ [kernel/kernel.c](kernel/kernel.c), [ARCHITECTURE.md](ARCHITECTURE.md)

**Want to understand memory management?**
→ [kernel/memory.c](kernel/memory.c), [include/memory.h](include/memory.h)

**Want to understand task scheduling?**
→ [kernel/scheduler.c](kernel/scheduler.c), [include/scheduler.h](include/scheduler.h)

**Want to understand VGA output?**
→ [kernel/screen.c](kernel/screen.c), [include/screen.h](include/screen.h)

**Want to understand the shell?**
→ [kernel/shell.c](kernel/shell.c), [include/shell.h](include/shell.h)

**Want to build the project?**
→ [BUILDING.md](BUILDING.md), [Makefile](Makefile)

**Want to test the project?**
→ [TEST_INSTRUCTIONS.md](TEST_INSTRUCTIONS.md)

## 📊 File Statistics

- **Total Files**: 27
- **Source Files**: 14 (8 C/ASM + 6 headers)
- **Documentation**: 10 files
- **Build System**: 3 files
- **Total Size**: ~78 KB
- **Lines of Code**: ~1,950

## ✅ Project Status

**COMPLETE AND READY TO BUILD**

All requirements implemented:
- ✓ 64-bit bootloader
- ✓ Kernel initialization
- ✓ Memory management with paging
- ✓ Task scheduler
- ✓ Shell with "Hello, Kernel!"
- ✓ Shell commands (echo, help, clear)
- ✓ VGA console output
- ✓ Clear folder structure
- ✓ Makefile
- ✓ Comprehensive documentation

## 🚀 Next Steps

1. Read [START_HERE.md](START_HERE.md)
2. Run `make run`
3. Explore the code
4. Read [ARCHITECTURE.md](ARCHITECTURE.md)
5. Modify and extend!

## 📞 Need Help?

- **Build issues?** → [BUILDING.md](BUILDING.md)
- **Runtime issues?** → [TEST_INSTRUCTIONS.md](TEST_INSTRUCTIONS.md)
- **Understanding code?** → [ARCHITECTURE.md](ARCHITECTURE.md)
- **Quick reference?** → [OVERVIEW.txt](OVERVIEW.txt)

---

**Ready to start?** → Open [START_HERE.md](START_HERE.md) and begin your journey! 🎉
