all: kernel

loader.o: loader.s
	nasm -f elf32 loader.s

kernel: loader.o link.ld
	ld -T link.ld -melf_i386 loader.o -o kernel.elf
	cp kernel.elf ../iso/boot/
	cd ../iso/ && ./geniso.sh	

run: kernel
	cd ../bochs/ && ./run_bochs.sh

clean:
	rm -f -r *.o kernel.elf ../iso/os.iso ../bochs/bochslog.txt
