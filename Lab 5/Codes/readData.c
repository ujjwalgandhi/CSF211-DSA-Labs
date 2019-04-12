#include "readData.h"

record* readRecords(record* records, char* file, int *final){
    int size = 5;
    record* records = (record*)malloc(sizeof(record)*size);
    
    FILE *fread;
    fread = fopen(file, "r");

    if (fread == NULL){
            printf("Error reading file!\n");
            exit(0);
    }

    int i=0;
    while(1){
        if (feof(fread)) 
            break;

        if(i == size){
            size*=2;
            records = (record*)realloc(records, sizeof(record)*size);
        }

        fscanf(fread, "\"%lld,%[^,],%[^,],%[^,],%[^\"]\"\n", &records[i].cnum, records[i].bcode, records[i].expdate, records[i].fname, records[i].lname);
        i++;
    }

    fclose(fread);
    *final = i;
    return records;
}