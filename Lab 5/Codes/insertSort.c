#include "insertSort.h"

void insertInOrder(record* records, int size, record newrec){
    int i=0;
    while ((records[i].cnum<newrec.cnum) || i==size-1){ 
        i++;
    }

    if (i==size-1){
        size *=2;
        records = (record*)realloc(records, sizeof(record)*size);
    }
    records[i] = newrec;
}

void insertionSort(record* records, int size){
    if (size==0) return;
    
    insertionSort(records, size-1);
    insertInOrder(records, size, records[size-1]);
}