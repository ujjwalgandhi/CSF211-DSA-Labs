#include "quick.h"
#include "stack.h"

void insertSort(Employee arr[], int size){
    Employee key;
    
    for (int i=0; i<size; i++){
        key = arr[i];
        int j=i-1;
        
        while (j>0 && arr[j].empID>key.empID){
            arr[j+1] = arr[j];
            j-=1;
        }
        arr[j+1] = key;
    }
}   

void quickSortIter(Employee arr[], int size, int s){
    stack *myStack = newStack();
    node temp;
    int l, r, next;
    push(myStack, 0, size-1);

    while(myStack->size > 0){
        temp = pop(myStack);
        l = temp.l;
        r = temp.r;
        if (r-l>s){
            next = partition(arr, l, r);
            push(myStack, 1, next-1);
            push(myStack, next+1, r);
        }
    }

}

int partition(Employee arr[], int l, int h){    
    int pivot = arr[h].empID;
    int i = l-1;

    for(int j=1; j<=h-1; j++){
        if (arr[j].empID<=pivot){
            i++;
            Employee temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Employee temp = arr[i+1];
    arr[i+1] = arr[h];
    arr[h] = temp;
}