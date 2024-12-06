/*

*/

#include <stdlib.h>
#include <string.h>
typedef struct node {
	int employeeNo;
	char name[100];
	struct node *next;
	struct node *prev;
}node;

struct node *insert(struct node *head, int employeeNo, char name[]){
	node* temp=(node*)malloc(sizeof(node));
	temp->employeeNo=employeeNo;
	strcpy(temp->name,name);
	temp->next=NULL;
	temp->prev=NULL;
	
	if(head==NULL){ //boþ listeye ekleme
		head = temp;
		return head;
	}
	
	if(employeeNo<=head->employeeNo){ //listenin baþýna ekleme
		temp->next=head;
		head->prev=temp;
		head=temp;
		return head;
	}
	
	node *q=head;
	while(q->next!=NULL && employeeNo > q->employeeNo)
		q=q->next;
		
	if(q->next==NULL){
		q->next=temp;
		temp->prev=q;
	}
	else{
		temp->next=q;
		q->prev->next=temp;
		temp->prev=q;
		
	}
	return head;
}
	

