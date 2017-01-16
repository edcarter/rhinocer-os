OBJECTS = loader.o kmain.o fb.o outb.o
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
         -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel.elf

kernel.elf: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

os.iso: kernel.elf
	cp kernel.elf ../iso/boot/
	cd ../iso && ./geniso.sh

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

loader.o: loader.s
	nasm -f elf32 loader.s

kernel: loader.o link.ld
	ld -T link.ld -melf_i386 loader.o -o kernel.elf
	cp kernel.elf ../iso/boot/
	cd ../iso/ && ./geniso.sh	

run: os.iso
	cd ../bochs/ && ./run_bochs.sh

clean:
	rm -f -r *.o kernel.elf ../iso/os.iso ../bochs/bochslog.txt ../iso/boot/kernel.elf
