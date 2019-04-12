#include "stack.h"

void push(struct linkedList *head, int ele){
	insertElement(head, ele);
}

int pop(struct linkedList *head){
	return deleteFirst(head);
}
