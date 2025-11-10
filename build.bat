@echo off
REM Build script for MinimalOS on Windows

echo Building MinimalOS...
echo.

REM Check if make is available
where make >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo Error: 'make' not found. Please install make or use WSL.
    exit /b 1
)

REM Build the OS
make clean
make

if %ERRORLEVEL% EQU 0 (
    echo.
    echo Build successful! OS image: os-image.bin
    echo.
    echo To run in QEMU:
    echo   qemu-system-x86_64 -drive format=raw,file=os-image.bin
) else (
    echo.
    echo Build failed!
    exit /b 1
)
