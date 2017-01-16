# rhinocer-os

### Getting Started
I followed the littleosbook guide on setting up the development environment. Their guide can be found at https://littleosbook.github.io/#first-steps

### Emulator
You will need the Bochs x86 emulator to run the OS.
http://bochs.sourceforge.net/

### Compiler/ Assembler
GCC and NASM are used to generate object files. LD is used to link them.

### Compiling and Running

To install dependencies on Ubuntu:
```
sudo apt-get install nasm gcc bochs bochs-x -y
```

To compile:
```
cd /rhinocer-os/src
make
```

To run on the Bochs emulator:
```
cd /rhinocer-os/src
make run
```

To cleanup temporary files:
```
cd /rhinocer-os/src
make clean
```
