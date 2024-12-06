#include <stdio.h>

struct node{
	int data;
	struct node *right;
	struct node *left;
};

struct node initialize(struct node *root,int data){
	struct node *temp=root;
	struct node *new;
	new->data=data;
	if(root==NULL){
		root->data=new->data;
		return *root;
	}
	while(temp!=NULL){
		if(new->data < temp->data){
			temp=temp->left;
		}
		if(new->data > temp->data)	{
			temp=temp->right;
		}
	}
	temp=new;
	return *root;
	
}

void main(){
	struct node *root=(struct node*)malloc(sizeof(struct node));
	initialize(root,20);
	initialize(root,10);
	initialize(root,12);
	initialize(root,45);
	initialize(root,92);
	initialize(root,3);
}
