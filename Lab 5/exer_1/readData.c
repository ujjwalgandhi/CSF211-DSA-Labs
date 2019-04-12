#include "readData.h"

Record* readFile(Record* rec, char* file, int* fsiz){
    int size = 5;
    rec = (Record*)malloc(sizeof(Record)*size);
    FILE *f = fopen(file, "r");

    if (f==NULL){
        printf("Error reading file\n");
        return NULL;
    }

    
}