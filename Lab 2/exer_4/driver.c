#include<stdio.h>
#include"linkedlist.h"
int main(int argc, char *argv[]){
	FILE *fileptr = fopen(argv[1], "r");
	
	struct linkedList *head = (struct linkedList *) malloc(sizeof(struct linkedList));
	int temp;
	fscanf(fileptr, "%d", &temp);
	while (!feof(fileptr)){
		insertFirst(head, temp);
		fscanf(fileptr, "%d", &temp);
	}
	
	fclose(fileptr);
	printList(head);
	deleteFirst(head);
	printList(head);
	
	FILE *fwrite = fopen("printList.txt", "w");
	struct node *ptr = head->first;
	fprintf(fwrite, "\n[");
	
	while (ptr->next!= NULL){
		fprintf(fwrite, "%d, ", ptr->element);
		ptr = ptr->next;
	}
	
	fprintf(fwrite, "%d]", ptr->element);
	return 0;
}
