#!/bin/bash
set -e

echo "Cleaning up previous build files..."
rm -f bin/root.o bin/main.o bin/string.o bin/os.o bin/stdio.o bin/calculadora.elf bin/calculadora.bin

echo "Assembling boot/root.s..."
arm-none-eabi-as -o bin/root.o boot/root.s

echo "Compiling user/main.c..."
arm-none-eabi-gcc -c -o bin/main.o user/main.c

echo "Compiling lib/string.c..."
arm-none-eabi-gcc -c -o bin/string.o lib/string.c

echo "Compiling os/os.c..."
arm-none-eabi-gcc -c -o bin/os.o Os/os.c

echo "Compiling lib/stdio.c..."
arm-none-eabi-gcc -c -o bin/stdio.o lib/stdio.c

echo "Linking object files..."
arm-none-eabi-gcc -nostdlib -nostartfiles -T boot/linker.ld -o bin/calculadora.elf \
  bin/root.o bin/main.o bin/string.o bin/os.o bin/stdio.o -lgcc

echo "Converting ELF to binary..."
arm-none-eabi-objcopy -O binary bin/calculadora.elf bin/calculadora.bin

echo "Running QEMU..."
qemu-system-arm -M versatilepb -nographic -kernel bin/calculadora.elf
