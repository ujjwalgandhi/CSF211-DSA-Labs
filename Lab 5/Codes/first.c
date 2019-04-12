#include "first.h"

int main(){
    FILE *fread, *fwrite;
    fread = fopen("10", "r");
    fwrite = fopen("result.txt", "w");
    
    record* records = (record*)malloc(sizeof(record)*size);
    
    //To calculate the time for the graph
    clock_t t;
    t = clock();

    int i = 0;
    while (1){

        if (fread == NULL){
            printf("Error reading file!\n");
            break;
        }

        if (feof(fread)) 
            break;

        //DEBUG
        //printf("Reading line %d\n", i); 
        
        if(i == size){
            size*=2;
            records = (record*)realloc(records, sizeof(record)*size);
        }

        fscanf(fread, "\"%lld,%[^,],%[^,],%[^,],%[^\"]\"\n", &records[i].cnum, records[i].bcode, records[i].expdate, records[i].fname, records[i].lname);
        i++;
    }

    t = clock() - t;
    //Stores the itme required for the operation to be completed
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    fprintf(fwrite, "Time taken for the program to read instructions: %lf\n", time_taken);

    insertionSort(records, 10);

    i=0;
    while (i<10){
        fprintf(fwrite, "Customer %d:\nCard num: %lld\nBank code: %s\nExpiry date: %s\nFirst name: %s\nLast Name: %s\n\n", i, records[i].cnum, records[i].bcode, records[i].expdate, records[i].fname, records[i].lname);
        i++;
    }
    free(records);
    fclose(fread);
    fclose(fwrite);

    
    return 0;
}

void insertInOrder(record* records, int size, record newrec){
    record rec = newrec, temp;
    for (int i=0; i<size; i++){
        if ((rec.cnum<records[i].cnum) || i==size-1){ 
            temp = rec;
            rec= records[i];
            records[i] = temp;
        }
    }
}

void insertionSort(record* records, int size){
    if (size==0) return;
    
    insertionSort(records, size-1);
    insertInOrder(records, size, records[size-1]);
}

// void insertInOrder(record* card_array, int n, record newcard){
// 	record card = newcard;
// 	record tempcard;
// 	for(int i=0;i<n;i++){
// 		if(card.cnum < card_array[i].cnum || i==n-1){
// 			tempcard = card;
// 			card = card_array[i];
// 			card_array[i] = tempcard;   
// 		}
// 	}
// }

// void insertionSort(record* card_array,int n){
// 	if(n==0){
// 		//topofstack = &n;
// 		return;
// 	}
// 	insertionSort(card_array,n-1);
// 	insertInOrder(card_array,n,card_array[n-1]);
// }