#include <stdio.h>

#define STACK_SIZE 10

typedef struct node {
char operation[100];
struct node *next;
} node;

typedef struct {
struct node *top;
int cnt;
} stack;

void push(stack,int);
void pop(stack);

int main() {
stack s;
s.top = NULL;
s.cnt = 0;

push(s, "Google Açýldý");
push(s, "Veri Yapýlarý Arandý");
push(s, "Stack Overflow Açýldý");

printf("Geçerli iþlem: %s\n", top(&s));
pop(s);
printf("Geri Aldýktan sonra, geçerli iþlem: %s\n", top(&s));


return 0;
}


void initialize(stack *stk){
	stk->top=NULL;
	stk->cnt=0;
}

void push(stack *stk, int c){
	if(stk->cnt==STACK_SIZE){
		printf("Stack is full.");
	}
	else{
		struct node *temp=(node*)malloc(sizeof(node));
		temp->operation=c;
		temp->next=stk->top;
		stk->top=temp;
		stk->cnt++;
	}
}

void pop(stack *stk){
	if(stk->cnt==0){
		printf("Stack is empty");
		return -100;
	}
	else{
		int x= stk->top->data;
		struct node * temp =stk->top->next;
		free(temp);
		stk->cnt--;
		return x;
	}
	
}

void top(stack *stk){
	
}







