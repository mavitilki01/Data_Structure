#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}stack;

typedef struct queue{
	int cnt;
	struct node *front;
	struct node *rear;
}queue;

int initialize(queue *q){
	q->cnt=0;
	q->front=q->rear=NULL;
}

int isFull(queue *q){
	if(q->cnt==SIZE)
		return 1;
	return 0;
	
}

int isEmpty(queue *q){
	
	if(q->cnt==0)
		return 0;
	return 1;
}

void enqueue(queue *q, int  data){
	
	if(isFull(q)){
		printf("Queue is full.\n");
	}
	else{
		stack *temp = (stack*)malloc(sizeof(stack));
		temp->data=data;
		temp->next=NULL;
		if(isEmpty(q)){
			q->front=q->rear=temp;
		}
		else{
			q->rear->next=temp;
			q->rear=temp;
		}
		q->cnt++;
	}
}

int dequeue(queue *q){
	if(isEmpty(q)){
		printf("Queue is empty.\n");
	}
	else{
		queue *temp=q->front;
		int x=q->front->data;
		q->front=temp->next;
		free(temp);
		q->cnt--;	
	}
}









