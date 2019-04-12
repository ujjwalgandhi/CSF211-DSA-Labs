#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int size = 5;

typedef struct record {
    long long int cnum;
    char bcode[6];
    char expdate[8];
    char fname[15];
    char lname[15];
} record;

void insertInOrder(record* records, int size, record newrec);
void insertionSort(record* records, int size);