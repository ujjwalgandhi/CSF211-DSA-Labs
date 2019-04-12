#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct 
{
    unsigned long long cnum;
    char bcode[5];
    char expdate[7];
    char fname[20];
    char lname[20];
} Record;

Record* readFile();
