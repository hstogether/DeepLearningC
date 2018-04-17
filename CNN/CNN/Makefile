all:cnn-hfp

cnn-hfp:main.o cnn.o minst.o mat.o
	riscv64-unknown-elf-gcc -o cnn-hfp main.o cnn.o minst.o mat.o -lm
main.o:
	riscv64-unknown-elf-gcc -c main.c
cnn.o:
	riscv64-unknown-elf-gcc -c cnn.c
minst.o:
	riscv64-unknown-elf-gcc -c minst.c
mat.o:
	riscv64-unknown-elf-gcc -c mat.c

clean:
	rm -rf *.o cnn-hfp
