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

void *insertDomain(NODE *node, char *domain, char *ip){
    
    char **domainArr = domainTokens(domain); //Returns the domain name as array
    int level = 0; //References the index of the domain array
    while(1){

        //If a key in the domain array already exists in the tree
        if (findKeyInChildren(node, domainArr[level])){
            node = findKeyInChildren(node, domainArr[level]);
            level++;
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
    NODE* new = newNode(node, ip);
}



void readData(FILE* fp, NODE* root, int lines){ //lines refers to the number of lines being read
    char domain[MAXLEN], ip[MAXLEN];
    int tokens;

    for (int i=0; i<lines; i++){
        fscanf(fp, "%[a-z-.] %[0-255.]\n", domain, ip);
        insertDomain(root, domain, ip);
    }
}

NODE* lookup(NODE* root, char* domain){
    if (root == NULL)
        return root;

    char** domainArr = domainTokens(domain);
    NODE* temp = root->child;
    int level = 1;
    while (temp){
        if (!strcmp(temp->key, domain[level-1])){

        }
    } 
}
