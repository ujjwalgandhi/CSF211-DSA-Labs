#include<stdio.h>
#include<stdlib.h>
#include "que.h"

typedef struct Mque{
	Queue *qq;
	int priority;
} Mque;

//typedef MultiQ* mque;


Mque* createMQ(int num);
Mque* addMQ(Mque mq, Element t);
Element nextMQ(Mque mq);
Element delNextMQ(MutliQ mq);
Element isEmptyMQ(Mque mq);
int sizeMQ(Mque mq);
int sizeMQbyPriority(Mque mq, Priority p);
Queue getQueueFromMQ(Mque mq, Priority p);
