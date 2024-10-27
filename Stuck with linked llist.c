#include <stdio.h>

typedef struct stuck{
	int data;
	struct stuck *next;
}stuck;

stuck *top = NULL;


void push(int data){
	stuck *new = (stuck*)malloc(sizeof(stuck));
	new->data=data;
	new->next=NULL;
	
	if(top!=NULL)
		new->next=top;
	top=new;
	
}

void pop(){
	if(top==NULL){
		printf("Stack is empty\n");
	}
	else{
		stuck *temp = top;	
		top=top->next;
		free(temp);
	}
	
}

int peek(){
	if(top==NULL){
		printf("Stack is empty\n");
		return 0;
	}
	return top->data;
}

int print(){
	stuck *temp= top;
	if(top==NULL){
		printf("Stack is empty\n");
		return 0;
	}
	
	for(temp;temp!=NULL;temp=temp->next){
		printf("%d ", temp->data);
	}
	return 0;
}


void main(){
	
	int choose, data;
	while(1){
	printf("\n1- Push");
	printf("\n2- Pop");
	printf("\n3- Peek");
	printf("\nChoose one: ");
	scanf("%d", &choose);
	
	switch(choose){
		case 1:
			printf("Enter value: ");
			scanf("%d", &data);
			push(data);
			print();
			break;
		case 2:
			pop();
			print();
			break;
		case 3:
			printf("%d", peek());
			break;
		default:
			printf("Wrong value!\n");
	}
	}
	
}
