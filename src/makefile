all: kernel

loader.o: loader.s
	nasm -f elf32 loader.s

kernel: loader.o link.ld
	ld -T link.ld -melf_i386 loader.o -o kernel.elf

clean:
	rm -f -r *.o kernel.elf
