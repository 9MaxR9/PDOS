nasm -f elf32 kernel.asm -o kasm.o
gcc -m32 -c kernel.c -o kc.o
ld -m elf_i386 -T link.ld -o PDOS.bin kasm.o kc.o
ld -m elf_i386 -T link.ld -o PDOS.img kasm.o kc.o
