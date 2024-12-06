#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define EMPTY 0
#define FULL 100

using namespace std;

typedef char data;

struct node{
	data d;
	struct node *next;
};
typedef struct node node;

struct stack{
 	int cnt; 	/* count of the elements */
 	struct node *top; 	/* pointer to the top element */
};
typedef struct stack stack;

bool isempty(stack *stk){
	return(stk -> cnt == EMPTY);
}

bool isfull(stack *stk){
	return (stk -> cnt == FULL);
}

void initialize(stack *stk){
 	stk -> cnt = 0; 		/* count of the elements */
	stk -> top = NULL; 		/* pointer to the top element */
}

data top(stack *stk){
	return (stk -> top -> d);
}

void push(data x, stack *stk){
    if(!isfull(stk)){
        /* create new node */
        node *temp = new node();
        temp -> d = x; 		//Write new data value
        temp -> next = stk -> top;

        /* assign the new node as top 	node */
        stk -> top = temp;
        stk -> cnt++;
    }
}

//stack dolu ise ve ben push yapmak istersem ne hatası....... overflow hatası
//stack boş ise ve ben pop yapmak istersem ne hatası........ underflow hatası

data pop(stack *stk){
    if(!isempty(stk)){
        data x; // will store the top data
        node *temp = stk->top;
        x = stk -> top -> d;
        stk -> top = stk -> top -> next;
        stk -> cnt--;
        delete(temp);
        return x;
    }
}

//stack LIFO (son giren ilk ��kar) yap�dadir.

int main(){
	char str[] = "CME227";
	int i;
	stack s;
	initialize(&s); 	/* initialize the stack */

	for(i = 0; str[i] != '\0'; ++i){	 /* fill stack */
		push(str[i], &s);
    }

	cout<<"String in the stack: "<<endl;

	while (!isempty(&s))
		cout<<pop(&s);
}
