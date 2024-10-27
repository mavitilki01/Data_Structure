#include <stdio.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *top=NULL;

int push(int data){
	node *new = (node*)malloc(sizeof(node));
	new->data=data;
	new->next=NULL;
	if(top!=NULL){
		new->next=top;
	}
	top=new;;
}

void pop(){
	if(top==NULL){
		printf("Stuck is empty.");
	}
	else{
		node *temp = top;
		top=top->next;
		free(temp);
	}
}

int peek(){
	if(top==NULL){
		printf("Stuck is empty.");
		return 0;
	}
	return top->data;
		
}

int print(){
	if(top==NULL){
		printf("Stuck is empty.");
		return 0;
	}
	node *temp = top;
	while(temp!=NULL){
		printf("%d ", temp->data);
		temp=temp->next;
	}
	return 0;
}


void main(){
	
	int choose, data;
	
	while(1){
		printf("\n1- Push");
		printf("\n2- Pop");
		printf("\n3- Peek");
		printf("\n4- Exit");
		printf("\nChoose one:");
		scanf("%d", &choose);
		
		switch(choose){
			case 1:
				printf("Enter a value: ");
				scanf("%d", &data);
				push(data);
				print();
				break;
			case 2:
				pop();
				print();
				break;
			case 3:
				printf("TOP ==> %d", peek());
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Wrong valid!");
		}
		}
	
}






