#include "multiq.h"

Mque* createMQ(int num){
	Mque* mq = (Mque*)malloc(sizeof(Mque)*num);
	for (int i=0; i<num; i++){
		mq[i].qq = newQ();
		mq[i].priority = i;
	}
	return mq;
}

Mque* addMQ(Mque* mq, Element* e){
	addQ((mq[e->priority]).qq, e);
}

Element* nextMQ(Mque mq){
	return front(
}
