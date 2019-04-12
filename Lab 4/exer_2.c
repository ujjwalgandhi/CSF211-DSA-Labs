#include<stdio.h>
#include<stdlib.h>
int* myalloc(int);
void myfree(int*, int);
int total = 0;


int main(){
    int space;
    printf("Enter number of spaces required: ");
    scanf("%d", &space);

    int* ptr = myalloc(space);
    if (ptr){
        printf("SUCCESS!\n");
        myfree(ptr, space);
        printf("MEMORY FREED!\n");
        return 1;
    }
    printf("ERROR!");
    return(-1);

}

void* myalloc(int space){
    void* p = malloc(space);
    total += space;
    return p;
}

void myfree(int* p, int space){
    total -= (sizeof(int)*space);
    free(p);
}