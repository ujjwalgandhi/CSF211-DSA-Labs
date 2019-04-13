#include "dns.h"

int main(int argc, char const *argv[])
{
    FILE *fp = NULL;
    fp = fopen(argv[1], "r");
    if (!fp){
        printf("Error opening the file\n");
        exit(-1);
    }

    //Creating the root node for the tree
    NODE* root = (NODE*)malloc(sizeof(NODE));
    root->parent = root->sibling = root->child = NULL;
    strcpy(root->key, "");

    int func, readNum;
    char searchKey[MAXLEN];
    while(!feof(fp)){
        fscanf(fp, "%d ", &func);
        
        if (func == -1) 
            return 0;

        else if (func == 1){ 
            fscanf(fp, "%d\n", &readNum);
            readData(fp, root, readNum);
        }

        else if (func == 2){ 
            fscanf(fp, "%s\n", searchKey);
            lookup(root, searchKey);
        }
    }

    return 0;
}