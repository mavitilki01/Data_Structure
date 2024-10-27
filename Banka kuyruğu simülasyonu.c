#include <stdio.h>
#include <stdlib.h>


/* Soru: Banka Kuyruðu Simülasyonu

Bir bankadaki müþteri sýrasýný yönetmek için bir kuyruk veri yapýsý tasarlamanýz isteniyor. Banka çalýþanlarý sýrasýyla kuyruða yeni müþteriler ekleyebilir ve sýradaki müþterileri iþlem yapmak üzere çaðýrabilir. Kuyruk, kapasitesi dolana kadar müþteri kabul edebilir.

Bir C programý yazarak, bu müþteri sýrasýný yöneten bir kuyruk (queue) sistemi oluþturun. Programýnýz þu özelliklere sahip olmalýdýr:

    Queue veri yapýsýný bir array kullanarak tasarlayýn. Maksimum kapasitesini 10 müþteri ile sýnýrlayýn.
    Queue iþlemleri için aþaðýdaki fonksiyonlarý tanýmlayýn:
        enqueue: Kuyruða yeni bir müþteri ekler. Eðer kuyruk doluysa hata mesajý verir.
        dequeue: Kuyruktan sýradaki müþteriyi çýkarýr ve çaðýrýlan müþteri numarasýný ekrana yazdýrýr. Eðer kuyruk boþsa hata mesajý verir.
        isEmpty: Kuyruðun boþ olup olmadýðýný kontrol eder.
        isFull: Kuyruðun dolu olup olmadýðýný kontrol eder.
    Program, kullanýcýya aþaðýdaki menüden seçim yapma imkaný vermelidir:

Menü:

1. Yeni müþteri ekle (Enqueue)
2. Müþteriyi çaðýr (Dequeue)
3. Kuyruðun boþ olup olmadýðýný kontrol et (Is Empty)
4. Kuyruðun dolu olup olmadýðýný kontrol et (Is Full)
5. Çýkýþ (Exit)

Çýktý Örneði:

1. Yeni müþteri ekle (Enqueue)
2. Müþteriyi çaðýr (Dequeue)
3. Kuyruðun boþ olup olmadýðýný kontrol et (Is Empty)
4. Kuyruðun dolu olup olmadýðýný kontrol et (Is Full)
5. Çýkýþ (Exit)
Seçiminizi yapýn: 1
Yeni müþteri numarasý girin: 101
Müþteri 101 kuyruða eklendi.

1. Yeni müþteri ekle (Enqueue)
2. Müþteriyi çaðýr (Dequeue)
3. Kuyruðun boþ olup olmadýðýný kontrol et (Is Empty)
4. Kuyruðun dolu olup olmadýðýný kontrol et (Is Full)
5. Çýkýþ (Exit)
Seçiminizi yapýn: 2
Sýradaki müþteri çaðrýldý: 101

...

Not: Programýnýzý dairesel bir kuyruk (circular queue) olarak tasarlayarak, kuyruk boþalana kadar yeni müþteri ekleme ve çýkarma iþlemlerini döngüsel bir yapýda gerçekleþtirin.
*/

#define SIZE 10

typedef struct{
	int front;
	int rear;
	int cnt;
	int data[SIZE];
}queue;




int initialize(queue *q){
	q->front=0;
	q->rear=-1;
	q->cnt=0;
	
}

typedef enum{false, true}bool;

bool isEmpty(queue *q){
	return(q->cnt==0);
}

bool isFull(queue *q){
	return (q->cnt==SIZE);
}


void enqueue(queue *q, int x){
	if(!isFull(q)){
		q->rear++;
		q->cnt++;
		if(q->rear==SIZE)
			q->rear=0;
		q->data[q->rear] = x;
		printf("\n%d siraya eklendi.\n");
	}
	else
		printf("\nKuyruk dolu!\n");
}

void dequeue(queue *q){

	if(!isEmpty(q)){
		int x= q->data[q->front];
		q->front++,
		q->cnt--;
		if(q->front==SIZE){
			q->front=0;
		}
		printf("\nSiradaki musteri cagirildi: %d", x);
	}
	else
		printf("\nYeni musteri yok!\n");
}

int main(){
	queue *node = (queue*)malloc(sizeof(queue));
	int choose, number;
	initialize(node);
	
	while(1){
		printf("\n1. Yeni musteri ekle (Enqueue)\n2. Musteriyi cagir (Dequeue)\n3. Kuyrugun bos olup olmadigini kontrol et (Is Empty)\n4. Kuyrugun dolu olup olmadigini kontrol et (Is Full)\n5. Cikis (Exit)\n");
		printf("\nSeciminizi yapin: ");
		scanf("%d", &choose);
		
		switch(choose){
			case 1:
				printf("\nYeni musteri numarasi giriniz: ");
				scanf("%d", &number);
				enqueue(node,number);
				break;
			case 2:
				dequeue(node);
				break;
			case 3:
				if(isEmpty(node))
					printf("\nKuyruk bos!\n");
				else{
					printf("\nKuyrukta %d kisi daha var\n", node->cnt);
				}
				break;
			case 4:
				if(isFull(node))
					printf("\nKuyruk dolu!\n");
				else
					printf("\nKuyrukta sadece %d kisi var\n", node->cnt);
				break;
					
			case 5:
				free(node);
				exit(0);
			default:
				printf("\nYanlýs deger girdiniz.\n");	
		}
	
	}	
		
}









