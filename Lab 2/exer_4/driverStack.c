#include"stack.h"
int main(int argc, char *argv[]){
	FILE *fileptr = fopen(argv[1], "r");
	
	struct linkedList *head = (struct linkedList *) malloc(sizeof(struct linkedList));
	int temp;
	fscanf(fileptr, "%d", &temp);
	while (!feof(fileptr)){
		push(head, temp);
		printList(head);
		fscanf(fileptr, "%d", &temp);
	}
	
	for (int i=0; i<5; i++){
		printf(pop(head));
		printList(head);	
	}
	
	return 0;
}
