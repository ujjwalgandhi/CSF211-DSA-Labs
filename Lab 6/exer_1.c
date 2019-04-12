#include "merge.h"

int main(){
	FILE* file;
	file = fopen("1024.txt", "r");
	
	int sz1 = 12, sz2 = 12;
	Element Ls1[sz1], Ls2[sz2], Ls[sz1+sz2];

	//printf("List 1:\n\n");
	for (int i=0; i<sz1; i++){
		fscanf(file, "%[^,],", Ls1[i].name);
		//printf("Name: %s\t", Ls1[i].name);
		fscanf(file, "%f\n", &Ls1[i].cgpa);
		// printf("CG: %.2f\n", Ls1[i].cgpa);
	}

	//printf("\nList 2:\n\n");
	for (int i=0; i<sz2; i++){
		fscanf(file, "%[^,],", Ls2[i].name);
		// printf("Name: %s\t", Ls2[i].name);
		fscanf(file, "%f\n", &Ls2[i].cgpa);
		// printf("CG: %.2f\n", Ls2[i].cgpa);

	}

	//printf("\nMerged:\n\n");
	merge(Ls1, sz1, Ls2, sz2, Ls);
	for (int i=0; i<sz1+sz2; i++){
		// printf("Name: %s\t", Ls[i].name);
		// printf("CG: %.2f\n", Ls[i].cgpa);
	}

	mergeSortIter(Ls1, sz1);
	for (int i=0; i<sz1; i++){
		printf("Name: %s\tCG: %.2f\n", Ls1[i].name, Ls1[i].cgpa);
	}
}
