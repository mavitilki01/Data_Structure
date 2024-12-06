#include <stdio.h>
#include <stdlib.h>
#define SIZE 10 // kuyruðun boyutunu belirliyoruz

typedef struct { // kuyruk yapýmýzý oluþturuyoruz
	int cnt;
	int rear, front;
	int data[SIZE];
} queue;



void initialize(queue *q){ // en baþta tanýmlamamýzý yapýyoruz.
	q->cnt=0;
	q->front=0;
	q->rear=-1;			// öncesinde attýrýrp iþlem yapacaðýmýz için -1den baþlatýyoruz
}

int isFull(queue *q){		//koyruk boþ mu dolu mu boþsa 0 doluysa 1 döndür
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

void enqueue(queue *q, int data){ // geriye bir þey döndürmüyor ekleme yapýyor(void)

	if(isFull(q)){					//kuyruk doluysa belirtip çýksýn
		printf("Kuyruk dolu\n");
	}
	else{							//kuyruk dolu deðilse:
		q->rear++;
		q->cnt++;
		if(q->rear==SIZE){
			q->rear=0;
		}
		q->data[q->rear]=data;}
		
	
}


int dequeue(queue *q){
	if(isEmpty(q)){
		printf("Kuyruk boþ!\n");
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
    if (isEmpty(q)) { // Kuyruk boþsa bir mesaj yazdýrýp fonksiyondan çýk
        printf("Kuyruk boþ!\n");
        return;
    }

    int i = q->front;
    int c = 0;
    printf("Kuyruktaki veriler: ");
    
    // Verileri dairesel olarak yazdýr
    for(c; c<q->cnt;c++){					//kuyruk doluysa rear ve front ayný olduðu için 
        printf("%d ", q->data[i]);			//hiçbir þey yazdýrmýyor bu yüzden ayrý bir counter kullanýyoruz
        i = (i + 1) % SIZE; // Bir sonraki elemana geç(i 10 a geçtiðinde geri 0 a dönmesi lazým)
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

