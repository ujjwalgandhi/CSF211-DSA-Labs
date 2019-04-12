list* createList(long long int n){
    list* ls = (list*)myalloc(sizeof(list));
    srand(time(0));
    
    list* temp = ls;
    for (long long int i=0; i<n; i++){
        temp->num = rand(); 
        temp->next = (list*)myalloc(sizeof(list));
        temp = temp->next;
    }
    temp->next = NULL;
    
    FILE *fptr;
    fptr = fopen("totalHeapSpace", "w");
    fptr.write(total);
    fptr.flush();
    fclose(fptr);

    return ls;
}

list* createCycle(list* ls){
    srand(time(0));
    int coin =rand()%2; //0 for linear and 1 for cyclic

    if (coin){
        int num = rand();
        list* last = ls, temp = ls;
        
        while(last->next)
            last = last->next
        
        while (temp->next){
            if(temp->num == num){ 
                last->next = temp;
                break;
            }
            temp = temp->next;
        }
    }

    return list;
}

int main(){
    long long int num;
    printf("Enter number of nodes: ");
    scanf("%d\n", &num);
    list* head = createList(num);
    
}
