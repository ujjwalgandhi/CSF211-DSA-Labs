#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	FILE *fread, *fwrite;
	fread = fopen(argv[1], "r");
	fwrite = fopen(argv[2], "w");
	
	if (fread == NULL){
		printf("Error reading the input file! Exiting.\n");
		exit(1);
	}
	
	if (fwrite == NULL){
		printf("The file to be written to doesn't exist exist or can't be created. Exiting.\n");
		exit(1);
	}
	
	char ch;
	while ((ch = getc(fread)) != EOF){
		putc(ch, fwrite);
	}
	
	return 0;
}
