all:cnn

cnn:main.o cnn.o minst.o mat.o
	gcc -o cnn main.o cnn.o minst.o mat.o -lm
main.o:
	gcc -c main.c
cnn.o:
	gcc -c cnn.c
minst.o:
	gcc -c minst.c
mat.o:
	gcc -c mat.c

clean:
	rm -rf *.o main
