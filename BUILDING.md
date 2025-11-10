# Building MinimalOS

## Prerequisites

### Linux/WSL
```bash
sudo apt-get update
sudo apt-get install build-essential nasm qemu-system-x86
```

### macOS
```bash
brew install nasm qemu
brew install x86_64-elf-gcc  # Cross compiler
```

### Windows
1. Install WSL (Windows Subsystem for Linux)
2. Follow Linux instructions above

Or use MinGW-w64:
- Install NASM from https://www.nasm.us/
- Install MinGW-w64
- Install QEMU from https://www.qemu.org/

## Cross Compiler

For proper kernel development, you need a cross-compiler:

```bash
# Install dependencies
sudo apt-get install build-essential bison flex libgmp3-dev libmpc-dev \
                     libmpfr-dev texinfo libisl-dev

# Download and build GCC cross-compiler
export PREFIX="$HOME/opt/cross"
export TARGET=x86_64-elf
export PATH="$PREFIX/bin:$PATH"

# Download binutils and gcc
wget https://ftp.gnu.org/gnu/binutils/binutils-2.40.tar.gz
wget https://ftp.gnu.org/gnu/gcc/gcc-13.1.0/gcc-13.1.0.tar.gz

# Build binutils
tar xf binutils-2.40.tar.gz
cd binutils-2.40
./configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install
cd ..

# Build GCC
tar xf gcc-13.1.0.tar.gz
cd gcc-13.1.0
./configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc
```

## Building

```bash
make clean
make
```

## Running

### QEMU
```bash
make run
# or
qemu-system-x86_64 -drive format=raw,file=os-image.bin
```

### VirtualBox
1. Create a new VM (Type: Other, Version: Other/Unknown 64-bit)
2. Allocate at least 64MB RAM
3. Create a new virtual hard disk
4. Use `dd` to write the image:
   ```bash
   dd if=os-image.bin of=/path/to/disk.vdi conv=notrunc
   ```

### Real Hardware (Advanced)
```bash
# Write to USB drive (BE CAREFUL - this will erase the drive!)
sudo dd if=os-image.bin of=/dev/sdX bs=512
```

## Troubleshooting

### "No bootable device" error
- Ensure the boot signature (0xAA55) is present
- Check that the bootloader is in the first sector

### Kernel doesn't load
- Verify the kernel is being loaded at the correct address (0x1000)
- Check disk read parameters in bootloader

### Screen output issues
- Ensure VGA memory is mapped correctly (0xB8000)
- Verify long mode is enabled before accessing VGA memory
