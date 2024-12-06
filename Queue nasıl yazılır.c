#include <stdio.h>
#include <stdlib.h>
#define SIZE 10 // kuyruðun boyutunu belirliyoruz

typedef struct { // kuyruk yapýmýzý oluþturuyoruz
	int cnt;
	struct node *front;
	struct node *rear;
} queue;

struct node {
	int data;
	struct node *next;
};

void initialize(queue *q){ // en baþta tanýmlamamýzý yapýyoruz.
	q->cnt=0;
	q->front=q->rear=0;
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
		struct node *temp =(struct node*)malloc(sizeof(struct node));
		temp->data=data;			//temp deðiþkeninde yer açýyoruz ve deðeri içine atýyoruz
		temp->next=NULL;
		if(isEmpty(q))				//eðer kuyruk boþsa front ve rear temp i göstersin
			q->front=q->rear=temp;	//ilk deðer!
		else{						//eðer kuyruk boþ deðilse:
			q->rear->next=temp;		//son elemanýn(rear) nexti tempi göstersin
			q->rear=temp;			//ve rearý temp e atarak tekrar son eleman olmasýný saðlayalým
		}
		q->cnt++;					//counter ý arttýrmayý unutma
	}
	
}


int dequeue(queue *q){		//FIFO prensibinden dolayý front kýsmýndan silme iþlemimizi yapýyoruz
	if(isEmpty(q)){
		printf("Kuyruk boþ!\n");		//kuyruk boþsa silinecek bir þey yoktur
		return 0;
	}
	else{
		struct node *temp=q->front;		//geçici bir deðiþken tanýmlýyoruz
		int x = temp->data;				//datayý sileceðimiz için bir deðiþkene aktarýyoruz
		q->front=temp->next;			//front u bir sonraki node a taþýyoruz 
		free(temp);						//en baþtaki node u siliyoruz
		q->cnt--;						//counter ý bir eksiltiyoruz
		return x;						// sildiðimiz datayý geri döndürüyoruz
	}
}
	
void print(queue *q){					//listeyi yazdýrma iþlemi
	struct node *temp=q->front;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
	


int main(){
	int choose, data;
	queue *q =(queue*)malloc(sizeof(queue));		//queue için sadece burada tanýmlama yapýp tüm fonksiyonlara gönderiyoruz.
	initialize(q);									//önce baþlatma fonksiyonumuzu yazýyoruz.
	
	while(1){		//sonsuz while döngüsüne alýyoruz ki kiþi döngüden çýkmak istediðinde kendi karar versin.
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

