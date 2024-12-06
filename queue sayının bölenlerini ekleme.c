#include <stdio.h>
#include <stdlib.h>


/*
Fonksiyona parametre olarak gelen sayýnýn tam bölenlerini, tanýmlanan "q" kuyruðuna sýrasýyla ekleyen fonksiyonu yazýnýz? 
( Ör: 12 sayýsý için; 1,2,3,4,6 ve 12 tam bölenleridir.)
*/

#define SIZE 100
typedef struct{
	int data[SIZE];
	int front;
	int rear;
	int counter;
}queue;


queue *initialize(queue *q){
	q->front=0;
	q->rear=-1;
	q->counter=0;
	return q;
	}
	

typedef enum{false,true}boolean;

boolean isEmpty(queue *q){
	return(q->counter==0);}

boolean isFull(queue *q){
	return(q->counter==SIZE);}

queue *enqueue(queue *q, int data){
	if(isFull(q)){
		printf("Queue is full.");
		return;
	}
	
	q->rear++;
	
	
	if(q->rear==SIZE-1)
		q->rear=0;
		
	q->data[q->rear]=data;
	q->counter++;
	return q;
}

queue *bolen(queue *q,int number){
	int i;
	for(i=1; i<=number;i++){
		if(number%i==0){
			enqueue(q,i);
		}
	}
	return q;
}

queue *display(queue *q){
	if(isEmpty(q)){printf("\nKuyruk bos\n"); return;
	}
	int i;
	for(i=q->front;i<=q->rear;i++){
		printf("%d ", q->data[i]);
	}
	printf("\n");
}

int main(){
	
	int number;
    queue q;
	initialize(&q);

    printf("Enter a number: ");
    scanf("%d", &number);

    bolen(&q, number);
    display(&q);

    return 0;
	
}
