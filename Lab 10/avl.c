#include<stdio.h>
#include<stdlib.h>

typedef struct AVL
{
	int val;
	struct AVL *left, *right;
	int bal : 2;
} AVL;

AVL* find(AVL *root, int value){
	if (value == root->val || !root)
		return root;

	if (value < root->val)
		return find(root->left, value);
	return find(root->right, value);
}

AVL* newNode(int value){
	AVL* node = (AVL*)malloc(sizeof(AVL));
	node->val = value;
	node->right = node->left = NULL;
	node->bal = 0;
	return node;
}

void add(AVL *root, int value){
	if (!root)
		return newNode(value);

	if (value < root->val){
		root->left = add(root->left, value);
		root->bal = -1;
	}
	else if (value > root->val){
		root->right = add(root->right, value);
		root->bal = 1;
	}

	return root;	
}

AVL* delete(AVL *root, int value){
	AVL *node = find(root, value);

	if (!root || !node)
		return root;

	if (value < root->val)
		root->left = delete(root->left, value);
	else if (value > root->val)
		root->right = delete(root->right, value);
	
	//The root node needs to be deleted or value is equal to root's value
	else{
		if (!(root->left)){
			AVL *temp = root->right;
			free(root);
			return temp;

			// root->val = (root->right)->val;
			// free(root->right);
		}
		else if (!(root->right)){
			AVL *temp = root->left;
			free(root);
			return temp;
		}

		AVL* temp = (AVL*)malloc(sizeof(AVL));
		temp = root->right;
		while (temp->left)
			temp = temp->left;

		root->val = temp->val;
		root->right = delete(root->right, temp->val);
	}
}

AVL* rotate(AVL *root, AVL* X, AVL* Y, AVL* Z, AVL* ParZ){
	AVL *a = X, *b = Y, *c = Z;
	AVL *T0 = X->left, *T1 = X->right, *T2 = Z->left, *T3 = Z->right;

	if (ParZ->left == Z)
		ParZ->left = b;
	else
		ParZ->right = b;

	b->left = a;
	b->right = c;
	a->left = T0;
	a->right = T1;
	c->left = T2;
	c->right = T3;

	return root;
}

int main(){

}