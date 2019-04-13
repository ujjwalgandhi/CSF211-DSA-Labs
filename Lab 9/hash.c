#include "hash.h"

int hashFunc(char *str, int base, int size){
	int asc = 0;	
	for (int i=0; i<strlen(str); i++){
		asc += str[i];
	}
	return ((asc%base)%size);
}

int countCol(char **arrStr, int base, int size){
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

char **parse(char *filename){
	FILE *file = NULL;
	file = fopen(filename, "r");

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
	fclose(file);
	return book;
}

int bestHash(){
	int table[3] = {5000, 50000, 500000};
	int **base = (int*)malloc(3*sizeof(int*));
	for (int i=0; i<3; i++){
		base[i] = (int)malloc(6*sizeof(int));
		for (int j=0; j<6; j++){
			base[i][j] = table[i]+1;
		}
	}
}

TABLE *createTable(){
	int tableSize = 5000;
	TABLE *hashTable = (TABLE*)malloc(sizeof(TABLE)*tableSize);

	for (int i=0; i<tableSize-1; i++){
		hashTable[i].next = &(hashTable[i+1]);
	}
	hashTable[tableSize-1].next = NULL;

	return hashTable;
}

TABLE *insert(TABLE *hashTable, char **words, int index){
	
}