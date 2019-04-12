#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct element{
	int value;
	int priority; //To be used in Q2
	struct element *next;
} Element;

typedef struct{
	Element *head;
	Element *tail;
	int size;
} Queue;

Queue* newQ();
bool isEmptyQ(Queue* q);
Queue* delQ(Queue* q);
Element* front(Queue* q);
Queue* addQ(Queue* q, Element* e);
int lengthQ(Queue* q);
