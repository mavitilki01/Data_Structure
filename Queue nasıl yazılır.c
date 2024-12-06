#include <stdio.h>
#include <stdlib.h>
#define SIZE 10 // kuyru�un boyutunu belirliyoruz

typedef struct { // kuyruk yap�m�z� olu�turuyoruz
	int cnt;
	struct node *front;
	struct node *rear;
} queue;

struct node {
	int data;
	struct node *next;
};

void initialize(queue *q){ // en ba�ta tan�mlamam�z� yap�yoruz.
	q->cnt=0;
	q->front=q->rear=0;
}

int isFull(queue *q){		//koyruk bo� mu dolu mu bo�sa 0 doluysa 1 d�nd�r
	if(q->cnt==SIZE){
		return 1;
	}
	else 
		return 0;
}

int isEmpty(queue *q){
	if(q->cnt==0){
		return 1;
	}
	else
		return 0;
}

void enqueue(queue *q, int data){ // geriye bir �ey d�nd�rm�yor ekleme yap�yor(void)

	if(isFull(q)){					//kuyruk doluysa belirtip ��ks�n
		printf("Kuyruk dolu\n");
		
	}
	else{							//kuyruk dolu de�ilse:
		struct node *temp =(struct node*)malloc(sizeof(struct node));
		temp->data=data;			//temp de�i�keninde yer a��yoruz ve de�eri i�ine at�yoruz
		temp->next=NULL;
		if(isEmpty(q))				//e�er kuyruk bo�sa front ve rear temp i g�stersin
			q->front=q->rear=temp;	//ilk de�er!
		else{						//e�er kuyruk bo� de�ilse:
			q->rear->next=temp;		//son eleman�n(rear) nexti tempi g�stersin
			q->rear=temp;			//ve rear� temp e atarak tekrar son eleman olmas�n� sa�layal�m
		}
		q->cnt++;					//counter � artt�rmay� unutma
	}
	
}


int dequeue(queue *q){		//FIFO prensibinden dolay� front k�sm�ndan silme i�lemimizi yap�yoruz
	if(isEmpty(q)){
		printf("Kuyruk bo�!\n");		//kuyruk bo�sa silinecek bir �ey yoktur
		return 0;
	}
	else{
		struct node *temp=q->front;		//ge�ici bir de�i�ken tan�ml�yoruz
		int x = temp->data;				//datay� silece�imiz i�in bir de�i�kene aktar�yoruz
		q->front=temp->next;			//front u bir sonraki node a ta��yoruz 
		free(temp);						//en ba�taki node u siliyoruz
		q->cnt--;						//counter � bir eksiltiyoruz
		return x;						// sildi�imiz datay� geri d�nd�r�yoruz
	}
}
	
void print(queue *q){					//listeyi yazd�rma i�lemi
	struct node *temp=q->front;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
	


int main(){
	int choose, data;
	queue *q =(queue*)malloc(sizeof(queue));		//queue i�in sadece burada tan�mlama yap�p t�m fonksiyonlara g�nderiyoruz.
	initialize(q);									//�nce ba�latma fonksiyonumuzu yaz�yoruz.
	
	while(1){		//sonsuz while d�ng�s�ne al�yoruz ki ki�i d�ng�den ��kmak istedi�inde kendi karar versin.
		printf("\n1- Add a data for queue\n2- Use data from queue\n3- Exit\nChoose one:");
		scanf("%d", &choose);
		switch(choose){
		case 1:
			printf("Enter a data for queue: ");
			scanf("%d",&data);
			enqueue(q,data);
			print(q);
			break;
		case 2:
			printf("%d cikarildi.",dequeue(q));
			print(q);
			break;
		case 3:
			printf("Kuyrukta %d kisi kaldi.", q->cnt);
			exit(0);
			break;
		default:
			printf("Wrong value!");
			break;
	}
	}
}

