# Installation Guide

Complete installation instructions for MinimalOS on different platforms.

## Table of Contents

- [Linux](#linux)
- [macOS](#macos)
- [Windows](#windows)
- [Cross-Compiler Setup](#cross-compiler-setup)
- [Verification](#verification)
- [Troubleshooting](#troubleshooting)

## Linux

### Ubuntu / Debian

```bash
# Update package list
sudo apt-get update

# Install required packages
sudo apt-get install -y \
    build-essential \
    nasm \
    qemu-system-x86 \
    git

# Optional: Install debugging tools
sudo apt-get install -y gdb

# Clone the repository
git clone https://github.com/yourusername/MinimalOS.git
cd MinimalOS

# Build and run
make
make run
```

### Arch Linux

```bash
# Install required packages
sudo pacman -S base-devel nasm qemu git

# Clone and build
git clone https://github.com/yourusername/MinimalOS.git
cd MinimalOS
make
make run
```

### Fedora / RHEL / CentOS

```bash
# Install required packages
sudo dnf groupinstall "Development Tools"
sudo dnf install nasm qemu-system-x86 git

# Clone and build
git clone https://github.com/yourusername/MinimalOS.git
cd MinimalOS
make
make run
```

## macOS

### Using Homebrew

```bash
# Install Homebrew if not already installed
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install required packages
brew install nasm qemu git

# For 32-bit compilation support
brew install i686-elf-gcc

# Clone and build
git clone https://github.com/yourusername/MinimalOS.git
cd MinimalOS
make
make run
```

### Alternative: Using MacPorts

```bash
# Install MacPorts from https://www.macports.org/

# Install required packages
sudo port install nasm qemu git

# Clone and build
git clone https://github.com/yourusername/MinimalOS.git
cd MinimalOS
make
make run
```

## Windows

### Option 1: WSL (Recommended)

1. **Install WSL**
   ```powershell
   # Run in PowerShell as Administrator
   wsl --install
   ```

2. **Restart your computer**

3. **Open WSL and follow Ubuntu instructions**
   ```bash
   # In WSL terminal
   sudo apt-get update
   sudo apt-get install build-essential nasm qemu-system-x86 git
   
   # Clone and build
   git clone https://github.com/yourusername/MinimalOS.git
   cd MinimalOS
   make
   make run
   ```

### Option 2: MinGW-w64

1. **Install MSYS2** from https://www.msys2.org/

2. **Open MSYS2 terminal and install packages**
   ```bash
   pacman -Syu
   pacman -S mingw-w64-x86_64-gcc nasm make git
   ```

3. **Install QEMU for Windows** from https://qemu.weilnetz.de/w64/

4. **Clone and build**
   ```bash
   git clone https://github.com/yourusername/MinimalOS.git
   cd MinimalOS
   make
   
   # Run with Windows QEMU
   "C:\Program Files\qemu\qemu-system-i386.exe" -kernel kernel.bin
   ```

### Option 3: Cygwin

1. **Install Cygwin** from https://www.cygwin.com/

2. **During installation, select these packages:**
   - gcc-core
   - gcc-g++
   - make
   - nasm
   - git

3. **Install QEMU separately** from https://qemu.weilnetz.de/w64/

4. **Build in Cygwin terminal**
   ```bash
   git clone https://github.com/yourusername/MinimalOS.git
   cd MinimalOS
   make
   ```

## Cross-Compiler Setup

For proper kernel development, a cross-compiler is recommended.

### Building GCC Cross-Compiler

```bash
# Install dependencies
sudo apt-get install build-essential bison flex libgmp3-dev \
                     libmpc-dev libmpfr-dev texinfo libisl-dev

# Set up environment
export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

# Create directories
mkdir -p $HOME/src
cd $HOME/src

# Download sources
wget https://ftp.gnu.org/gnu/binutils/binutils-2.40.tar.gz
wget https://ftp.gnu.org/gnu/gcc/gcc-13.1.0/gcc-13.1.0.tar.gz

# Build binutils
tar xf binutils-2.40.tar.gz
mkdir build-binutils
cd build-binutils
../binutils-2.40/configure --target=$TARGET --prefix="$PREFIX" \
    --with-sysroot --disable-nls --disable-werror
make -j$(nproc)
make install
cd ..

# Build GCC
tar xf gcc-13.1.0.tar.gz
mkdir build-gcc
cd build-gcc
../gcc-13.1.0/configure --target=$TARGET --prefix="$PREFIX" \
    --disable-nls --enable-languages=c --without-headers
make all-gcc -j$(nproc)
make all-target-libgcc -j$(nproc)
make install-gcc
make install-target-libgcc
```

### Using the Cross-Compiler

Update Makefile to use cross-compiler:
```makefile
CC = i686-elf-gcc
LD = i686-elf-ld
```

## Verification

### Check Installation

```bash
# Check GCC
gcc --version
# or
i686-elf-gcc --version

# Check NASM
nasm -version

# Check QEMU
qemu-system-i386 --version

# Check Make
make --version
```

### Build Test

```bash
cd MinimalOS
make clean
make

# Should output:
# nasm -f elf32 boot/multiboot_header.asm -o boot/multiboot_header.o
# nasm -f elf32 kernel/kernel_entry.asm -o kernel/kernel_entry.o
# gcc -m32 ... -c kernel/kernel.c -o kernel/kernel.o
# ...
# Kernel built: kernel.bin
```

### Run Test

```bash
make run

# Should open QEMU window showing:
# =================================
#    MinimalOS x86_64 Kernel
# =================================
# 
# Initializing memory management... [OK]
# Initializing scheduler... [OK]
# Initializing shell... [OK]
# 
# Kernel initialization complete!
# 
# Hello, Kernel!
```

## Troubleshooting

### Common Issues

#### "gcc: error: unrecognized command line option '-m32'"

**Solution**: Install 32-bit libraries
```bash
# Ubuntu/Debian
sudo apt-get install gcc-multilib

# Fedora
sudo dnf install glibc-devel.i686
```

#### "nasm: command not found"

**Solution**: Install NASM
```bash
# Ubuntu/Debian
sudo apt-get install nasm

# macOS
brew install nasm

# Windows (MSYS2)
pacman -S nasm
```

#### "qemu-system-i386: command not found"

**Solution**: Install QEMU
```bash
# Ubuntu/Debian
sudo apt-get install qemu-system-x86

# macOS
brew install qemu

# Windows: Download from https://qemu.weilnetz.de/w64/
```

#### QEMU shows black screen

**Solutions**:
1. Check kernel.bin was created: `ls -lh kernel.bin`
2. Try with serial output: `qemu-system-i386 -kernel kernel.bin -serial stdio`
3. Check multiboot header: `readelf -h kernel.bin`

#### Build fails with linker errors

**Solution**: Ensure using correct linker flags
```bash
# Check Makefile has:
LDFLAGS = -T linker.ld -nostdlib -melf_i386
```

#### Permission denied when running make

**Solution**: Ensure files are executable
```bash
chmod +x Makefile
```

### Getting More Help

- Check [GitHub Issues](https://github.com/chetanbhargavv/MinimalOS/issues)
- Read [TROUBLESHOOTING.md](TROUBLESHOOTING.md)
- Ask in [Discussions](https://github.com/chetanbhargavv/MinimalOS/discussions)

## Next Steps

After successful installation:

1. Read [README.md](README.md) for project overview
2. Check [ARCHITECTURE.md](ARCHITECTURE.md) for technical details
3. Try modifying the code and rebuilding
4. Read [CONTRIBUTING.md](CONTRIBUTING.md) to contribute

---

**Installation successful?** Star ⭐ the repository and start exploring!
