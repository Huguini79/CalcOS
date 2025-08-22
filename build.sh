clear
nasm -f elf32 src/kernel/kernel.asm -o build/kernel.asm.o
nasm -f elf32 src/drivers/io/io.asm -o build/io.asm.o
gcc -I./src -m32 -ffreestanding -nostdlib -fno-exceptions -c src/kernel/kernel.c -o build/kernel.o
gcc -I./src -m32 -ffreestanding -nostdlib -fno-exceptions -c src/drivers/vga/vga.c -o build/vga.o
gcc -I./src -m32 -ffreestanding -nostdlib -fno-exceptions -c src/drivers/keyboard/keyboard.c -o build/keyboard.o
gcc -I./src -m32 -ffreestanding -nostdlib -fno-exceptions -c src/programs/calculadora/calculadora.c -o build/calculadora.o
gcc -I./src -m32 -ffreestanding -nostdlib -fno-exceptions -c src/kernel/string.c -o build/string.o
ld -m elf_i386 -T src/linker/linker.ld -o iso/boot/kernel build/kernel.asm.o build/kernel.o build/vga.o build/io.asm.o build/keyboard.o build/calculadora.o build/string.o
grub-mkrescue -o bin/CalcOS.iso iso
qemu-system-x86_64 -m 1024 -cdrom bin/CalcOS.iso
