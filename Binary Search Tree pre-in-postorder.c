#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *right;
	struct node *left;
}btree;

btree* newNode(int data){
	btree *new  =(btree*)malloc(sizeof(btree));
	
	new->data=data;
	new->left=NULL;
	new->right=NULL;
	return new;
}

btree* insert(btree *root, int data){
	if(root==NULL){
		root = newNode(data);
		return root;
	}
	if(data<root->data){
		root->left=insert(root->left,data);
	}
	else{
		root->right=insert(root->right,data);
	}
}

void preorder(btree *root){
	if(root!=NULL){
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(btree *root){
	if(root!=NULL){
		preorder(root->left);
		printf("%d ", root->data);
		preorder(root->right);
	}
}
void postorder(btree *root){
	if(root!=NULL){
		preorder(root->left);
		preorder(root->right);
		printf("%d ", root->data);
	}
}

int main(){
	btree *root=(btree*)malloc(sizeof(btree));
	printf("inserting:");
	root=insert(root,20);root=insert(root,59);
	root=insert(root,50);root=insert(root,32);
	root=insert(root,90);root=insert(root,117);
	
	preorder(root);
	inorder(root);
	postorder(root);
	
	
	return 0;
}
