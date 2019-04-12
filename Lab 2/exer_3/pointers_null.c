#include<stdio.h>
int main(){
	int *ptr = NULL;
	printf("The value of ptr is : %x\n", ptr);
//	printf("The value stored at ptr is : %x\n", *ptr);
	
	if (ptr)
		printf("Pointer not null\n");
	if (!ptr)
		printf("Pointer is null\n");
		
		return 0;
}
