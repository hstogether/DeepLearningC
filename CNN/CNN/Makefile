all:cnn-hfp-host

cnn-hfp-host:main.o cnn.o minst.o mat.o
	gcc -o cnn-hfp-host main.o cnn.o minst.o mat.o -lm
main.o: 
	gcc -c main.c cnn.h
cnn.o:
	gcc -c cnn.c
minst.o:
	gcc -c minst.c
mat.o:
	gcc -c mat.c

clean:
	rm -rf *.o cnn-hfp-host
