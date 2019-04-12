#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char name[10];
	float cgpa;
} Element;

int min(int e1, int e2);
void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);
void mergeSortRec(Element Ls[], int size);
void mergeSortIter(Element Ls[], int size);
int recSpace;
int iterSpace;