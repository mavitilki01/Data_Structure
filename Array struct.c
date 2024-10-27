#include <stdio.h>
#define SIZE 7

int stuck[SIZE];
int top =-1, i;

void push(int data){
	if(top==SIZE-1){
		printf("Stuck is full.\n");
	}
	else{
		top++;
		stuck[top]= data;
	}
	
}

void pop(){
	if(top==-1){
		printf("Stuck is empty\n");
	}
	else
		top--;
}

int peek(){
	return stuck[top];
}
void print(){
	for(i=0;i<=top;i++){
		printf("%d ", stuck[i]);
	}
	printf("\n");
}

int main(){
	int choose, data;
	
	while(1){
		printf("1- Push\n");
	printf("2- Pop\n");
	printf("3- Peek\n");
	printf("Choose: ");
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
			printf("TOP ==> %d\n", peek());
			break;
		default:
			printf("Wrong statement!\n");
	}
	}
		return 0;
}

