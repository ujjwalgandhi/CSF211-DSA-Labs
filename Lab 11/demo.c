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

char** domainTokens(char* domain){
    int tokens = countTokens(domain);
    char **domainArr = (char**)malloc(tokens);
    for(int i=0; i<tokens; i++){
        domainArr[i] = (char*)malloc(MAXKEY);
    }
    
    char *token = (char*)malloc(sizeof(char)*MAXKEY); 
    token = strtok(domain, ".");
    domainArr[tokens-1] = token;
    int i = tokens-2; 
    
    while(token != NULL){
        token = strtok(NULL, ".");
        domainArr[i--] = token; 
    }

    return domainArr;
}

NODE* findKeyInChildren(NODE* node, char* key){
    NODE* temp = node->child;
    while (temp){
        if (!strcmp(node->key, key))
            return node;
        temp = temp->sibling;
    }
    return NULL;
}

NODE* newNode(NODE* parent, char* key){
    NODE* new = (NODE*)malloc(sizeof(NODE));
    parent->child = new;
    new->parent = parent;
    new->sibling = new->child = NULL;
    strcpy(new->key, key);

    return new;
}

void insertDomain(NODE *node, char *domain, char *ip){
    
    char **domainArr = domainTokens(domain); //Returns the domain name as array
    int level = 0; //References the index of the domain array
    while(1){

        //If a key in the domain array already exists in the tree
        if (findKeyInChildren(node, domainArr[level])){
            node = findKeyInChildren(node, domainArr[level]);
            level++;
            if (level == countTokens(domain))
                break;
        }
        else{
            //Creating a new child of the node if it has no child
            if (!node->child){
                NODE *new = newNode(node, domainArr[level]);
                node = new;
            }

            //If the node already has children, add a child to the right of rightmost child
            else{
                NODE *temp = node->child, *prev = NULL;
                while (temp){
                    prev = temp;
                    temp = temp->sibling;
                }

                NODE *new = newNode(node, domainArr[level]);
                prev->sibling = new;
            }

            //To break the loop when all domain keys have been inserted
            level++;
            if (level == countTokens(domain))
                break;
        }
    }
}

void readData(FILE *fp, NODE *root, int lines){ //lines refers to the number of lines being read
    char domain[MAXLEN], ip[MAXLEN];

    for (int i=0; i<1; i++){
        fscanf(fp, "%s %s\n", domain, ip);
        // fscanf(fp, "%[a-z-.] %[0-255]\n", domain, ip);
        printf("%s %s\n", domain, ip);
        insertDomain(root, domain, ip);
    }
}

void printData(NODE *root){
    while (root){
        printf("%s\n", (root->child)->key);
        printData(root->child);
        root = root->sibling;
    }
}

int main(int argc, char const *argv[]){
    char domain[MAXKEY] = "bits-pilani.ac.in";
    int tokens = countTokens(domain);
    printf("%d\n", tokens);

    char** new = domainTokens(domain);
    for (int i=0; i<tokens; i++){
        printf("%d. %s\n", i, new[i]);
    }

    //Creating a new node
    NODE* root = (NODE*)malloc(sizeof(NODE));
    root->parent = root->sibling = root->child = NULL;
    strcpy(root->key, "");

    FILE *fp = NULL;
    fp = fopen("input.txt", "r");
    if (fp == NULL)
        printf("Error opening the file!\n");
    int readNum, func;

    fscanf(fp, "%d ", &func);
    printf("%d\n", func);
    if (func == 1){
        fscanf(fp, "%d\n", &readNum);
        printf("%d\n", readNum);
        readData(fp, root, readNum);
    }
    // printData(root);
    fclose(fp);
    
    return 0;
}
