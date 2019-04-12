#include "que.h"

Queue* newQ(){
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
	return q;
}

bool isEmptyQ(Queue* q){
	if (q->size == 0) return true;
	return false;
}

Queue* delQ(Queue* q){
	if (isEmptyQ(q)) return q;

	Element* new = (Element*)malloc(sizeof(Element));
	new = q->head->next;
	q->head->next = NULL;
	q->head = new;
	(q->size)--;
	return q;
}

Element* front(Queue* q){
	return q->head;
}

Queue* addQ(Queue* q, Element* e){
	if (isEmptyQ(q)){
		q->head = e;
		q->tail = e;
		return q;
	}
	q->tail->next = e;
	q->tail = e;
	q->tail->next = NULL;
	(q->size)++;
	return q;
}

int lengthQ(Queue* q){
	if (isEmptyQ(q)) return 0;
	//return q->size;

	int count =	 0;
	Element *counter = (Element*)malloc(sizeof(Element));
	counter = q->head;
	while (counter){
		count++;
		counter = counter->next;
	}
	return count;
}
