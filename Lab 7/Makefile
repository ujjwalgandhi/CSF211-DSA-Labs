run: output
	./output

output: exer_1.o quick.o
	gcc -o output exer_1.o quick.o

exer_1.o: exer_1.c quick.h
	gcc -C exer_1.c

quick.o: quick.c quick.h
	gcc -C quick.c