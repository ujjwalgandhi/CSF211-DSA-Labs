#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLEN 100
#define MAXKEY 30

typedef struct node{
    char key[MAXKEY];
    struct node *parent, *child, *sibling;
} NODE;

int countTokens(char* string);
char** domainTokens(char* domain);
NODE* findKeyInChildren(NODE* node, char* key);
void *insertDomain(NODE *node, char *domain, char *ip);
void readData(FILE* fp, NODE* root, int lines);
NODE* lookup(NODE* root, char* word);