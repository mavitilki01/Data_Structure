#include <stdio.h>
#include <stdlib.h>
	
	struct node* headNode(struct node*,int);
	struct node* tailNode(struct node*,int);
	int counting(struct node*);
	struct node* print(struct node*);
	struct node {
		int data;
	struct node *next;
	};
	
	int main(){
		struct node* head=NULL;
		
		int veri, total;
		
		
		printf("Enter a data to add to list's head= ");
		scanf("%d", &veri);
		head= headNode(head, veri);
		
		
		printf("Enter a data to add to list's tail= ");
		scanf("%d", &veri);
		head= tailNode(head,veri);
		
		total=counting(head);
		printf("There is %d node\n", total);
		
		printf("what there is?:\n");
		print(head);
		
		
	}
	
	struct node* headNode(struct node *head, int veri){
		struct node *new;
		new = (struct node*)malloc(sizeof(struct node));
		new->data=veri;
		new->next=head;
		head=new;
		
		return head;
	}
	
	struct node *tailNode(struct node *head, int veri){
		struct node *new;
		new = (struct node*)malloc(sizeof(struct node));
		new->data=veri;
		new->next = NULL;
		
		if(head==NULL){
			head=new;
		}
		else{
			struct node* last=head;
			
			while(last->next!=NULL){
				last=last->next;
			}
			last->next=new;
		}
		return head;
		
	}
	
	int counting(struct node* head){
		int i=0;
		struct node* temp=head;
		
		while(temp!=NULL){
			temp=temp->next;
			i++;
		}
		return i;
	}
	
	struct node* print(struct node* head){
	struct node* temp=head;
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	return head;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
