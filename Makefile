all: libtads.a main.c
	gcc -g -o main main.c -I tads -L . -ltads -lm
libtads.a: tads/Vetor.c tads/Vetor.h 
	gcc -g -c tads/Vetor.c -o tads/Vetor.o
	ar -crs libtads.a tads/Vetor.o
run:
	./main
val:
	valgrind ./main