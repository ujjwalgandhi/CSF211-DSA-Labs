run: output
	./output

output: exer_1.o merge_2.o 
	gcc -o output merge_2.o exer_1.o 

exer_1.o: exer_1.c merge.h
	gcc -c exer_1.c

merge_2.o: merge_2.c merge.h
	gcc -c merge_2.c