#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 100
int num = 0;

int hashFunc(char *str, int base, int size){
	int asc = 0;	
	for (int i=0; i<strlen(str); i++){
		asc += str[i];
	}
	return ((asc%base)%size);
}

int countCol(char *arrStr[], int base, int size){
	int count = 0;
	int hash[size];
	for (int i=0; i<size; i++){
		hash[i] = hashFunc(arrStr[i], base, size);
		for (int j=0; j<i; j++){
			if (hash[j] == hash[i]){
				count++;
				break;
			}
		}
	}
	return count;
}

char** parse(char* filename){
	FILE *file = fopen(filename, "r");

	if (!file){
			printf("Unable to open the file\n");
			return NULL;
	}

	int bookLen = 100;
	char c = ' ';
	char **book = (char**)malloc(sizeof(char*)*bookLen);

	while(!feof(file)){
		char string[MAX] = {'\0'};
		
		if (c != ' '){
			fscanf(file, "%[a-zA-Z]", string);
			c = fgetc(file);
			continue;
		}

		fscanf(file, "%[a-zA-Z]", string);
		c = fgetc(file);

		if (c != ' '){
			fscanf(file, "%[a-zA-Z]", string);
			c = fgetc(file);
			continue;
		}

		if (string[0] != '\0'){
			num++;
			if (num>bookLen){
				bookLen*=2;
				book = (char**)realloc(book, sizeof(char*)*bookLen);
			}
			book[num-1] = (char*)malloc(sizeof(char)*strlen(string));
			strcpy(book[num-1], string);
		}
	}

	printf("There are %d word(s)\n", num);
	return book;
}

int main(){
	char **book = parse("aliceinwonderland.txt");
	for (int i=0; i<num; i++)
		printf("%s\n", book[i]);
	printf("There are %d word(s)\n", num);

	return 0;
}