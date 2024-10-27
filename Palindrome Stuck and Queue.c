#include <stdio.h>

#define SIZE 50;

typedef struct stuck{
	char cumle[SIZE];
	struct stuck *next;
}stuck;

stuck *top= NULL;


void push(char data){
	stuck *new = (stuck*)malloc(sizeof(malloc));
	new->cumle=data;
	new->next=NULL;
	if(top!=NULL)
		new->next=top;
	top=new;
	
}

void main(){
	
	char sentence[SIZE];
	
	push(sentence);
	
	
	
}








