#include<stdio.h>

typedef struct {
    char name[10];
    int empID;
} Employee;

void quickSortIter(Employee arr[], int size, int s);
void insertSort(Employee arr[], int size);
int partition(Employee arr[], int l, int h);