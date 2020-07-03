all: clean build

build: main.c factor.o
	@gcc -Wall -m32 main.c factor.o -o factor

factor.o: factor.asm
	@nasm -g -f elf -o factor.o factor.asm

clean:
	@rm -f factor
	@rm -f factor.o
