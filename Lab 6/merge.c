#include "merge.h"

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]){
    for (int i=0, j=0, k=0; k < (sz1+sz2); k++){
        if (i>=sz1){
            strcpy(Ls[k].name, Ls2[j].name);
            Ls[k].cgpa = Ls2[j].cgpa;
            j++;
        }

        if (j>=sz2){
            strcpy(Ls[k].name, Ls1[i].name);
            Ls[k].cgpa = Ls1[i].cgpa;
            i++;
        }
        
        if (i<sz1 && j<sz2 && (Ls1[i].cgpa<Ls2[j].cgpa)){
            strcpy(Ls[k].name, Ls1[i].name);
            Ls[k].cgpa = Ls1[i].cgpa;
            i++;
        }

        else if (i<sz1 && j<sz2 && (Ls1[i].cgpa>=Ls2[j].cgpa)){
            strcpy(Ls[k].name, Ls2[j].name);
            Ls[k].cgpa = Ls2[j].cgpa;
            j++;
        }
    }
}

void mergeSortRec(Element Ls[], int size){
    printf("%d\n", size);
    if (size>1){
        Element merged[size];
        int mid = size/2;
        printf("\tMid: %d\n", mid); //degub

        mergeSortRec(Ls, mid);
        mergeSortRec(Ls+mid, size-mid);

        merge(Ls, mid, Ls+mid, size-mid, merged);
        for (int i=0; i<size; i++){
            Ls[i] = merged[i]; 
        }
    }
}