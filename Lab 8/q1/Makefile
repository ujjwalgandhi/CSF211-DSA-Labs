run: output
	./output

output: List.o main.o
	gcc -o output List.o main.o

main.o: main.c List.h
	gcc -C main.c

List.o: List.c List.h
	gcc -C List.c