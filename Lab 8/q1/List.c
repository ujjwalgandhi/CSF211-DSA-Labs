#include "List.h"

List createList(Student studArray, int arraySize){
    List newList = (List)malloc(sizeof(struct list));
    Node nodeList = (Node)malloc(sizeof(struct node)*arraySize);

    for (int i=0; i<arraySize; i++){
        nodeList[i].record = &(studArray[i]);
        nodeList[i].next = &(nodeList[i+1]);

        if (i==arraySize-1)
            nodeList[i].next = NULL;
    }

    newList->count = arraySize;
    newList->first = &(nodeList[0]);
    newList->last = &(nodeList[arraySize-1]);
}

void insertInOrder(List list, Node newNode){
    Node temp = list->first, prev = NULL;

    //IF NODE IS INSERTED IN AN EMPTY LIST
    if (list->count == 0){
        newNode->next = NULL;
        list->first = list->last = newNode;
        (list->count)++;
        return;
    }
    
    //IF NODE IS INSERTED AT THE FIRST POSITION
    if ((newNode->record)->marks < (temp->record)->marks){
        newNode->next = temp;
        list->first = newNode;
        (list->count)++;
        return;
    }
    
    //IF NODE IS INSERTED AT ANY OF THE OTHER POSITIONS
    while(temp != NULL && ((newNode->record)->marks > (temp->record)->marks)){
        prev = temp;
        temp = temp->next;
    }

    if (prev == list->last) 
        list->last = newNode;

    newNode->next = temp;
    prev->next = newNode;
    (list->count)++;
    return;
}

List insertionSort(List list){
    //BASIC IDEA - 
    //SORT LIST OF SIZE ONE SMALLER  
    //INSERT THE LAST ELEMENT USING THE FUNCTION

    List l = (List)malloc(sizeof(struct list));
    l->count = 0;
    l->first = l->last = NULL;

    Node temp = list->first, next;
    // l->count = list->count - 1;
    // l->first = (list->first)->next;

    // if (l == NULL) return;

    while(temp){
        next = temp->next;
        insertInOrder(l, temp);
        temp = next;
    }

    return l;

    // printf("h");
    // insertionSort(l);
    // printf("j");
    // insertInOrder(l, n);
    // printf("k");
}

double measureSortingTime(List list){
    clock_t start, end;
    double time;

    start = clock();
    insertionSort(list);
    end = clock();

    time = (double) (end-start)/CLOCKS_PER_SEC;
    return time*1000;
}

void * myalloc(int size){
    globalCounter+=size+4;
    int* alloc = (int*)malloc(size+4);
    *alloc = size;
    return (void*)alloc+4; 
}

void myfree(void* ptr){
    int* read = (int*)(ptr-4);
    int size = *read;
    globalCounter-=size;
    free(read);
}

