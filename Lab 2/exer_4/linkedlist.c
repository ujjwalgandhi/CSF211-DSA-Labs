#include "linkedlist.h"

void insertFirst(struct linkedList *head, int ele){
	struct node *link = (struct node *) malloc(sizeof(struct node));
	link->element = ele;
	
	link->next = head->first;
	
	head->first = link;
	head->count++;
}

struct node *deleteFirst(struct linkedList *head){
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	temp = head->first;
	head->first = temp->next;
	head->count--;
	
	return temp;
}

void printList(struct linkedList *head){
	struct node *ptr = head->first;
	printf("\n[");
	
	while (ptr->next!= NULL){
		printf("%d, ", ptr->element);
		ptr = ptr->next;
	}
	
	printf("%d]\n", ptr->element);
}

struct node *delete(struct linkedList *head, int ele){
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	
	struct node *ptr = head->first;
	while(ptr->next != NULL){
		if (ptr->next->element == ele){
			temp = ptr->next;
			temp->next = ptr->next->next;
			return temp;
		}
		ptr = ptr->next;
	}
	return NULL;
}

int search(struct linkedList *head, int ele){
	struct node *ptr = head->first;
	
	while (ptr != NULL){
		if (ptr->element == ele)
			return 1;
	}
	return 0;
}
