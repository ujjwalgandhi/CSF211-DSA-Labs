#include "dns.h"

int countTokens(char* string){
    int size=1;

    for (int i=0; i<strlen(string); i++){
        if (string[i]=='.') 
            size++;
    }

    return size;
}

//Returns an array with domain keys as elements in the reverse order
//Eg: bits-pilani.ac.in
//returns array with elements
//1: in
//2: ac
//3: bits-pilani
char** domainTokens(char* domain){
    int tokens = countTokens(domain);
    char **domainArr = (char**)malloc(tokens);
    for(int i=0; i<tokens; i++){
        domainArr[i] = (char*)malloc(MAXKEY);
    }
    
    char *token = strtok(domain, ".");
    domainArr[tokens-1] = token;
    int i = tokens-2; 
    
    while(token != NULL){
        token = strtok(NULL, ".");
        domainArr[i--] = token; 
    }

    return domainArr;
}

//Finds if the entered key exists in the given node's children
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

    //Setting last node's child equal to the IP address
    NODE *new = newNode(node, ip);
}

//Reads data from the file into the tree
void readData(FILE *fp, NODE *root, int lines){ //lines refers to the number of lines being read
    char domain[MAXLEN], ip[MAXLEN];

    for (int i=0; i<lines; i++){
        fscanf(fp, "%[a-z-.] %[0-255.]\n", domain, ip);
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

void lookup(NODE *root, char *domain){
    if (root == NULL)
        return;

    char **domainArr = domainTokens(domain);
    int level = 0;
    NODE *temp = root;
    char errorCode[MAXKEY] = ""; 

    while (1){
        if (findKeyInChildren(temp, domainArr[level])){
            temp = findKeyInChildren(temp, domainArr[level]);
            //strcat(errorCode);

            level++;
            if (level == countTokens(domain))
                break;
        }

        else{
            printf("The entered DNS does not exist\n");
            //printf("Error code - %s\n", errorCode);
            return;
        }
    }

    printf("The IP address for this DNS is %s\n", (temp->child)->key);
}