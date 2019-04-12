#include "stack.h"

stack* newStack(){
    stack* st = (stack*)malloc(sizeof(stack));
    st->top = NULL;
    st->size = 0;
    return st;
}

void push(stack* st, int a, int b){
    node* n = (node*)malloc(sizeof(node));
    n->l = a;
    n->r = b;
    n->next = st->top;
    st->top = n;
    (st->size)++;
}

node popen(stack* st){
    node n;
    if (!st->size){
        n.l = -1;
        n.r = -1;
        n.next = NULL;
        return n;
    }

    n = *(st->top);
    st->top = (st->top)->next;
    (st->size)--;
    return n;
}