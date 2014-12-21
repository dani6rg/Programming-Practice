main.o: main.c
	gcc -c main.c
module1.o: module1.c
	gcc -c module1.c
module2.o: module2.c
	gcc -c module2.c
program: main.o module1.o module2.o
	gcc main.o module1.o module2.o -o program
all: program

run: program
	./program
clean:
	rm -f main.o module1.o module2.o