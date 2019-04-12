#include<stdio.h>
int main(int argc, char *argv[]){
	printf("Number of arguments: %d and first one is: %s\n", argc, argv[0]);
	for (int i=0; i<argc; i++){
		printf("%s ", argv[i]);
	}
	printf("\n");
}
