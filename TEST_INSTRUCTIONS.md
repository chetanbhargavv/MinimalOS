# Testing MinimalOS

## Prerequisites Check

Before building, verify you have the required tools:

```bash
# Check NASM
nasm -v
# Expected: NASM version 2.x or higher

# Check GCC
gcc --version
# Expected: GCC 7.x or higher

# Check Make
make --version
# Expected: GNU Make 4.x or higher

# Check QEMU (optional, for testing)
qemu-system-x86_64 --version
# Expected: QEMU emulator version 4.x or higher
```

## Build Process

### Step 1: Clean Previous Builds
```bash
make clean
```

Expected output:
```
rm -f boot/*.bin kernel/*.o kernel.bin os-image.bin
```

### Step 2: Build the OS
```bash
make
```

Expected output:
```
nasm -f bin boot/boot.asm -o boot/boot.bin
nasm -f elf64 kernel/kernel_entry.asm -o kernel/kernel_entry.o
gcc -m64 -ffreestanding -fno-pie -fno-stack-protector -nostdlib -nostdinc -mno-red-zone -I./include -O2 -Wall -Wextra -c kernel/kernel.c -o kernel/kernel.o
gcc -m64 -ffreestanding -fno-pie -fno-stack-protector -nostdlib -nostdinc -mno-red-zone -I./include -O2 -Wall -Wextra -c kernel/screen.c -o kernel/screen.o
gcc -m64 -ffreestanding -fno-pie -fno-stack-protector -nostdlib -nostdinc -mno-red-zone -I./include -O2 -Wall -Wextra -c kernel/memory.c -o kernel/memory.o
gcc -m64 -ffreestanding -fno-pie -fno-stack-protector -nostdlib -nostdinc -mno-red-zone -I./include -O2 -Wall -Wextra -c kernel/scheduler.c -o kernel/scheduler.o
gcc -m64 -ffreestanding -fno-pie -fno-stack-protector -nostdlib -nostdinc -mno-red-zone -I./include -O2 -Wall -Wextra -c kernel/shell.c -o kernel/shell.o
gcc -m64 -ffreestanding -fno-pie -fno-stack-protector -nostdlib -nostdinc -mno-red-zone -I./include -O2 -Wall -Wextra -c kernel/string.c -o kernel/string.o
ld -T linker.ld -nostdlib -o kernel.bin kernel/kernel_entry.o kernel/kernel.o kernel/screen.o kernel/memory.o kernel/scheduler.o kernel/shell.o kernel/string.o
cat boot/boot.bin kernel.bin > os-image.bin
OS image created: os-image.bin
```

### Step 3: Verify Build
```bash
ls -lh os-image.bin
```

Expected: File size should be around 10-20 KB

## Running the OS

### Option 1: QEMU (Recommended)
```bash
make run
```

Or manually:
```bash
qemu-system-x86_64 -drive format=raw,file=os-image.bin
```

### Option 2: QEMU with Serial Output
```bash
qemu-system-x86_64 -drive format=raw,file=os-image.bin -serial stdio
```

### Option 3: QEMU with Debugging
```bash
qemu-system-x86_64 -drive format=raw,file=os-image.bin -d int,cpu_reset -no-reboot
```

## Expected Output

When you run the OS, you should see:

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

kernel> clear
(clear command ready - would clear screen)

kernel> 

Shell demo complete. Kernel running...
```

## Verification Checklist

### Boot Sequence
- [ ] BIOS loads bootloader
- [ ] Bootloader prints "Booting MinimalOS..."
- [ ] Bootloader prints "Loading kernel..."
- [ ] Screen clears and shows kernel banner
- [ ] Cyan-colored banner appears

### Initialization
- [ ] "Initializing memory management... [OK]" appears in green
- [ ] "Initializing scheduler... [OK]" appears in green
- [ ] "Initializing shell... [OK]" appears in green
- [ ] "Kernel initialization complete!" appears

### Shell
- [ ] "Hello, Kernel!" appears in yellow
- [ ] Welcome message appears
- [ ] Shell prompt "kernel> " appears in green
- [ ] Help command output is displayed
- [ ] Echo command output is displayed
- [ ] Clear command message is displayed

## Troubleshooting

### Build Errors

#### Error: "nasm: command not found"
**Solution**: Install NASM
```bash
# Ubuntu/Debian
sudo apt-get install nasm

# macOS
brew install nasm

# Windows
# Download from https://www.nasm.us/
```

#### Error: "gcc: command not found"
**Solution**: Install GCC
```bash
# Ubuntu/Debian
sudo apt-get install build-essential

# macOS
xcode-select --install

# Windows
# Use WSL or MinGW-w64
```

#### Error: "ld: cannot find -lgcc"
**Solution**: This is expected for freestanding environment. The Makefile is configured correctly.

#### Error: Undefined references
**Solution**: Check that all .o files are being linked. Verify Makefile KERNEL_OBJS list.

### Runtime Errors

#### QEMU shows black screen
**Possible causes**:
1. Boot signature missing
   - Check boot.asm has `dw 0xAA55` at end
2. Kernel not loaded
   - Verify disk_load function in bootloader
3. VGA memory not accessible
   - Ensure paging is set up correctly

**Debug**:
```bash
qemu-system-x86_64 -drive format=raw,file=os-image.bin -d int,cpu_reset -no-reboot
```

#### QEMU shows "No bootable device"
**Possible causes**:
1. os-image.bin not created
   - Run `make` again
2. Boot signature incorrect
   - Verify boot.asm

**Debug**:
```bash
hexdump -C os-image.bin | head -n 32
# Should see 0xAA55 at offset 0x1FE
```

#### Kernel crashes or reboots
**Possible causes**:
1. Stack overflow
   - Increase kernel stack size in kernel_entry.asm
2. Page fault
   - Check paging setup in boot.asm
3. Invalid memory access
   - Verify memory addresses

**Debug**:
```bash
qemu-system-x86_64 -drive format=raw,file=os-image.bin -d int -no-reboot
```

#### No output after boot
**Possible causes**:
1. VGA memory not mapped
   - Check paging includes 0xB8000
2. Screen initialization failed
   - Add debug output before screen_init()

### Testing Individual Components

#### Test Bootloader Only
```bash
qemu-system-x86_64 -drive format=raw,file=boot/boot.bin
```
Expected: Should see boot messages

#### Test Kernel Binary
```bash
objdump -d kernel.bin | less
```
Expected: Should see disassembled code

#### Check Boot Signature
```bash
hexdump -C os-image.bin | grep "aa55"
```
Expected: Should see "55 aa" at offset 0x1FE

#### Verify Kernel Load Address
```bash
objdump -h kernel.bin
```
Expected: Sections should start at 0x100000

## Performance Testing

### Boot Time
Measure time from power-on to shell prompt:
```bash
time qemu-system-x86_64 -drive format=raw,file=os-image.bin -display none -serial stdio
```

Expected: < 1 second

### Memory Usage
Check kernel size:
```bash
size kernel.bin
```

Expected: text + data + bss < 100KB

## Advanced Testing

### Test on Real Hardware (Advanced)
```bash
# WARNING: This will erase the USB drive!
sudo dd if=os-image.bin of=/dev/sdX bs=512
```

### Test with Different QEMU Options
```bash
# More memory
qemu-system-x86_64 -m 128M -drive format=raw,file=os-image.bin

# Different CPU
qemu-system-x86_64 -cpu qemu64 -drive format=raw,file=os-image.bin

# Enable KVM (if available)
qemu-system-x86_64 -enable-kvm -drive format=raw,file=os-image.bin
```

## Success Criteria

✅ Build completes without errors
✅ os-image.bin is created
✅ QEMU boots the OS
✅ Kernel banner appears
✅ All subsystems initialize successfully
✅ "Hello, Kernel!" is displayed
✅ Shell prompt appears
✅ Commands execute correctly

## Next Steps After Testing

1. **Experiment**: Modify the code and rebuild
2. **Add Features**: Implement keyboard input
3. **Debug**: Use QEMU debugging features
4. **Learn**: Read the architecture documentation
5. **Extend**: Add new shell commands

## Getting Help

If you encounter issues:
1. Check BUILDING.md for detailed build instructions
2. Review ARCHITECTURE.md for system design
3. Read inline code comments
4. Check OSDev Wiki: https://wiki.osdev.org/
5. Verify all prerequisites are installed

## Test Report Template

```
Date: ___________
System: ___________
GCC Version: ___________
NASM Version: ___________
QEMU Version: ___________

Build Status: [ ] Pass [ ] Fail
Boot Status: [ ] Pass [ ] Fail
Kernel Init: [ ] Pass [ ] Fail
Shell Output: [ ] Pass [ ] Fail

Notes:
_________________________________
_________________________________
_________________________________
```
