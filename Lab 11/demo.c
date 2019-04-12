#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLEN 100
#define MAXKEY 30

typedef struct node{
    char key[MAXKEY];
    struct node *parent, *child, *sibling;
} NODE;


int countTokens(char* string){
    int size=1;

    for (int i=0; i<strlen(string); i++){
        if (string[i]=='.') 
            size++;
    }

    return size;
}



int main(int argc, char const *argv[])
{
    char domain[MAXKEY] = "bits-pilani.ac.in";
    int tokens = countTokens(domain);
    printf("%d\n", tokens);

    char** new = domainTokens(domain);
    for (int i=0; i<tokens; i++){
        printf("%d. %s\n", i, new[i]);
    }

    return 0;
}
