#include "qsort.h"

void exchange(int* a, int* b){
	int c = *a;
	*a = *b; 
	*b = c;
}

void printArray(int* studArray, int arrSize)
{
	// printing the array
	int i = 0;
	for(i=0;i<arrSize;i++)
	{
		printf("Arr[%d] is %d\n", i, studArray[i]);
	}
}

int* readData(char * fileName){
	FILE* file = fopen(fileName, "r");
	fscanf(file, "%d\n", &size);

	int* values = (int*)malloc(sizeof(int)*size);
	char name[10];

	int i=0;
	while(!feof(file)){
		fscanf(file, "%s\t%d\n", name, &values[i]);
		i++;
	}

	fclose(file);
	return values;
}

KeyStruct extractKeys(int* Ls, int lsSize, int loKey, int hiKey){
	int sizeNew = hiKey-loKey+1;
	int *newArr = (int*)malloc(sizeof(int)*sizeNew);

	for (int i=0; i<sizeNew; i++)
		newArr[i]=0;

	for (int i=0; i<lsSize; i++){
		if (newArr[Ls[i]-loKey] == 0)
			newArr[Ls[i]-loKey]= Ls[i];
	}

	int numKeys=0;
	for(int i=0; i<sizeNew; i++){
		if(newArr[i]) 
			numKeys++;
	}

	int* keyArray = (int*)malloc(sizeof(int)*numKeys);
	int j=0;
	for(int i=0; i<lsSize; i++){
		if (newArr[i]){
			keyArray[j] = newArr[i];
			j++;
		}
	}

	KeyStruct key = (KeyStruct)malloc(sizeof(struct keyStruct));
	key->Keys = keyArray;
	key->keysSize = numKeys;

	return key;
}

int part2Loc(int* Ls, int lo, int hi, int piv){

	for (int i=lo; i<hi; i++){
		if (Ls[i]==piv){
			exchange(Ls+i, Ls+hi);
			break;
		}
	}
	
	int i=lo-1;
	for (int j=lo; j<hi; j++){
		if (Ls[j]<=piv){
			i++;
			exchange(Ls+i, Ls+j);
		}
		exchange(Ls+i, Ls+j);
	}
	exchange(Ls+i+1, Ls+hi);

	return i+1;
}

void quickSortKnownKeyRange(int * Ls, int size, int loKey, int hiKey){
	KeyStruct key = extractKeys(Ls, size, loKey, hiKey);
	for(int i=0; i<key->keysSize; i++){
		part2Loc(Ls, 0, size-1, key->Keys[i]);
	}
}
