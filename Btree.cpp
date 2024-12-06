#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *right;
	struct node *left;
}btree;

btree* newNode(int data){
	btree *newnode =(btree*)malloc(sizeof(btree));
	
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
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
	return root;
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
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
void postorder(btree *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}
int main() {
    btree *root = NULL; // Baþlangýçta kök NULL olmalý
    
    // Aðaç elemanlarýný ekliyoruz
    root = insert(root, 50);
    root = insert(root, 25);
    root = insert(root, 75);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 27);
    root = insert(root, 70);


    // Farklý dolaþým türlerini yazdýrýyoruz
    printf("Preorder Dolaþým: ");
    preorder(root);
    printf("\n");

    printf("Inorder Dolaþým: ");
    inorder(root);
    printf("\n");

    printf("Postorder Dolaþým: ");
    postorder(root);
    printf("\n");

    return 0;
	}
