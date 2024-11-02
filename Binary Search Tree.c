#include <stdio.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}btree;

btree *newNode(int data){
	btree *p =(btree*)malloc(sizeof(btree));
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}

void inorder(btree *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

btree* insert(btree *root, int data){
	if(root == NULL){
		return newNode(data);
	}
	if(data < root->data)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);

	return root;
}

int main(){
	btree *myroot=NULL;
	int data=0;
	do{
		printf("\nAgaca veri eklemek için sayý giriniz === \n");
		scanf("%d", &data);
		if(data!=-1)
			myroot= insert(myroot,data);
			
	}while(data!=-1);
	printf("\n");
	inorder(myroot);
	printf("\n");
	getchar();
	return 0;
}



