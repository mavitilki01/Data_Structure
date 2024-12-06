#include <stdio.h>
#include <stdlib.h>
#define SIZE 10 // kuyru�un boyutunu belirliyoruz

typedef struct { // kuyruk yap�m�z� olu�turuyoruz
	int cnt;
	int rear, front;
	int data[SIZE];
} queue;



void initialize(queue *q){ // en ba�ta tan�mlamam�z� yap�yoruz.
	q->cnt=0;
	q->front=0;
	q->rear=-1;			// �ncesinde att�r�rp i�lem yapaca��m�z i�in -1den ba�lat�yoruz
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
		q->rear++;
		q->cnt++;
		if(q->rear==SIZE){
			q->rear=0;
		}
		q->data[q->rear]=data;}
		
	
}


int dequeue(queue *q){
	if(isEmpty(q)){
		printf("Kuyruk bo�!\n");
		return 0;
	}
	else{
		int x= q->data[q->front];
		q->front++;
		q->cnt--;
		if(q->front==SIZE)
			q->front=0;
		return x;
	}
}
	
void print(queue *q) {
    if (isEmpty(q)) { // Kuyruk bo�sa bir mesaj yazd�r�p fonksiyondan ��k
        printf("Kuyruk bo�!\n");
        return;
    }

    int i = q->front;
    int c = 0;
    printf("Kuyruktaki veriler: ");
    
    // Verileri dairesel olarak yazd�r
    for(c; c<q->cnt;c++){					//kuyruk doluysa rear ve front ayn� oldu�u i�in 
        printf("%d ", q->data[i]);			//hi�bir �ey yazd�rm�yor bu y�zden ayr� bir counter kullan�yoruz
        i = (i + 1) % SIZE; // Bir sonraki elemana ge�(i 10 a ge�ti�inde geri 0 a d�nmesi laz�m)
    }
    
    printf("\n");
}


int main(){
	int choose, data;
	queue *q =(queue*)malloc(sizeof(queue));
	initialize(q);
	
	while(1){
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
			printf("%d cikarildi.\n",dequeue(q));
			print(q);
			break;
		case 3:
			printf("Kuyrukta %d kisi kaldi.", q->cnt);
			exit(0);
			break;
		default:
			printf("Wrong value!\n");
			break;
	}
	}
	
	
	
}

