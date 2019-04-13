#include "hash.h"

int main(){
	char **book = parse("aliceinwonderland.txt");
	for (int i=0; i<num; i++)
		printf("%s\n", book[i]);
	printf("There are %d word(s)\n", num);

	return 0;
}