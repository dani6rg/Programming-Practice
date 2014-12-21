xor2.o: xor2.c
	gcc -c xor2.c -O3
all: xor2.o
	gcc xor2.o -o xor
clean:
	rm -f xor2.o
