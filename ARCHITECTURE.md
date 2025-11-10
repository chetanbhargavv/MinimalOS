# MinimalOS Architecture

## Overview

MinimalOS is a minimal x86_64 operating system kernel demonstrating fundamental OS concepts:
- Bootloader and mode transitions (Real → Protected → Long mode)
- Memory management with paging
- Task scheduling
- Basic I/O (VGA text mode)
- Simple shell interface

## Boot Process

### 1. BIOS Boot (Real Mode - 16-bit)
- BIOS loads first sector (boot.asm) to 0x7C00
- Bootloader initializes segments and stack
- Loads kernel from disk sectors 2-16 to 0x1000

### 2. Protected Mode Transition (32-bit)
- Enable A20 line for extended memory access
- Load GDT (Global Descriptor Table)
- Set CR0.PE bit to enter protected mode
- Jump to 32-bit code segment

### 3. Long Mode Setup (64-bit)
- Setup identity paging (PML4 → PDP → PD)
- Enable PAE (Physical Address Extension)
- Set EFER.LME bit to enable long mode
- Enable paging (CR0.PG)
- Load 64-bit GDT
- Jump to 64-bit code

### 4. Kernel Initialization
- Setup kernel stack
- Initialize VGA screen driver
- Initialize memory allocator
- Initialize task scheduler
- Start shell

## Memory Layout

```
0x00000000 - 0x000003FF  Real Mode IVT
0x00000400 - 0x000004FF  BIOS Data Area
0x00000500 - 0x00007BFF  Free (conventional memory)
0x00007C00 - 0x00007DFF  Bootloader (512 bytes)
0x00007E00 - 0x0007FFFF  Free
0x00080000 - 0x0009FFFF  Extended BIOS Data Area
0x000A0000 - 0x000BFFFF  Video Memory
0x000C0000 - 0x000FFFFF  BIOS ROM
0x00100000 - 0x001FFFFF  Kernel code/data (1MB)
0x00200000 - 0x005FFFFF  Kernel heap (4MB)
0x00600000+              Free memory
```

## Paging Structure

```
PML4 (Page Map Level 4)
  └─> PDP (Page Directory Pointer)
       └─> PD (Page Directory)
            └─> 2MB huge page (identity mapped)
```

The bootloader sets up identity paging for the first 2MB, mapping virtual addresses 1:1 to physical addresses.

## Kernel Components

### Screen Driver (screen.c)
- VGA text mode (80x25 characters)
- Color support (16 foreground, 8 background colors)
- Scrolling when screen is full
- Character output functions

### Memory Manager (memory.c)
- Simple bump allocator (kmalloc)
- 4MB heap starting at 2MB
- 16-byte alignment
- Basic memory utilities (memset, memcpy)

### Scheduler (scheduler.c)
- Round-robin task scheduling
- Up to 8 concurrent tasks
- 8KB stack per task
- Task states: READY, RUNNING, BLOCKED
- Note: Context switching not fully implemented (simplified for demo)

### Shell (shell.c)
- Command prompt interface
- Built-in commands:
  - `help` - Display available commands
  - `echo` - Echo arguments to screen
  - `clear` - Clear screen
- Demonstrates kernel functionality

## GDT Structure

### 32-bit Protected Mode GDT
```
0: Null descriptor
1: Code segment (base=0, limit=4GB, executable, readable)
2: Data segment (base=0, limit=4GB, writable)
```

### 64-bit Long Mode GDT
```
0: Null descriptor
1: 64-bit code segment
2: 64-bit data segment
```

## Interrupt Handling

Currently not implemented. A full OS would include:
- IDT (Interrupt Descriptor Table)
- ISRs (Interrupt Service Routines)
- Timer interrupt for preemptive scheduling
- Keyboard interrupt for input

## Future Enhancements

1. **Interrupt Support**
   - IDT setup
   - Timer interrupt (PIT/APIC)
   - Keyboard driver

2. **Full Context Switching**
   - Save/restore CPU registers
   - TSS (Task State Segment)
   - Proper task switching

3. **Memory Management**
   - Physical memory manager
   - Virtual memory allocator
   - Page fault handler
   - Free list management

4. **File System**
   - Simple FS implementation
   - Disk driver
   - File operations

5. **System Calls**
   - Syscall interface
   - User mode support
   - Privilege level switching

6. **Networking**
   - Network driver
   - TCP/IP stack
   - Socket interface
