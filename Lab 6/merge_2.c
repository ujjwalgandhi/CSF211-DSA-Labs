#include "merge.h"

int min(int e1, int e2){
	return (e1<e2?e1:e2);
}

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]){
    int i=0, j=0, k=0;

    while (i<sz1 && j<sz2){
        if (Ls1[i].cgpa<=Ls2[j].cgpa){
            Ls[k] = Ls1[i];
            i++;
        }
        else {
            Ls[k] = Ls2[j];
            j++;
        }

        k++;
    }

    while (i < sz1){ 
        Ls[k] = Ls1[i]; 
        i++; 
        k++; 
    } 

    while (j < sz2){ 
        Ls[k] = Ls2[j]; 
        j++; 
        k++; 
    }
}

void mergeSortRec(Element Ls[], int size){
    if (size==1) return;
    
    Element merged[size];
    int mid = size/2;

    recSpace += sizeof(int)+size*sizeof(Element);

    mergeSortRec(Ls, mid);
    mergeSortRec(Ls+mid, size-mid);

    merge(Ls, mid, Ls+mid, size-mid, merged);
    for (int i=0; i<size; i++){
        Ls[i] = merged[i]; 
    }
}


void mergeSortIter(Element arr[], int size){
    int mid, right;
    for (int curr_size=1; curr_size<size; curr_size*=2){
        //printf("CurrSize: %d\n", curr_size);
        for (int start=0; start<size; start+=2*curr_size){
            //printf("  Start: %d\n", start);
            mid = min(start+curr_size-1, size-1);
            right = min(start+2*curr_size-1, size-1);

            Element new[right-start+1];
            merge(arr+start, mid-start+1, arr+mid+1, right-mid, new);

            for(int i=0;i<right-start+1;i++){
				arr[start+i]=new[i];
            }
        }
    }
}