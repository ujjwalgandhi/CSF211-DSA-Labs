#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 100
int num = 0;
int elementCost;
int insertionCost;
int queryingCost;

typedef struct table{
    int hash;
    struct table *next;
} TABLE;

typedef struct node{
    char key[MAX];
    int count;
    struct node *next;
} NODE;

int hashFunc(char *str, int base, int size);
int countCol(char *arrStr[], int base, int size);
char **parse(char *filename);
int bestHash();
TABLE *createTable();
TABLE *insert(TABLE *hashTable, char **words, int index);