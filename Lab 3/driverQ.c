#include "que.h"

int main(){
	struct Element *el1 = (struct Element *)malloc(sizeof(struct Element));
	el1->value=5;
	struct Element *el2 = (struct Element *)malloc(sizeof(struct Element));
	el1->value=6;
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q = newQ();
	printf("Is queue empty: %d\n", isEmptyQ(q));
	addQ(q, el1);
	addQ(q, el2);
	printf("Is queue empty: %d\n", isEmptyQ(q));
	printf("Length: %d\n", lengthQ(q));
	
	return 0;
}
