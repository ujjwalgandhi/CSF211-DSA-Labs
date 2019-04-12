#include <stdio.h>

typedef struct {
    int l;
    int r;
    struct node* next;
} node;

typedef struct{
    node* top;
    int size;
} stack;

stack* newStack();
void push(stack* st, int a, int b);
node pop(stack* st);
