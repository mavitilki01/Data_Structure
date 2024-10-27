#include <stdio.h>
#include <stdlib.h>


/* Soru: Banka Kuyru�u Sim�lasyonu

Bir bankadaki m��teri s�ras�n� y�netmek i�in bir kuyruk veri yap�s� tasarlaman�z isteniyor. Banka �al��anlar� s�ras�yla kuyru�a yeni m��teriler ekleyebilir ve s�radaki m��terileri i�lem yapmak �zere �a��rabilir. Kuyruk, kapasitesi dolana kadar m��teri kabul edebilir.

Bir C program� yazarak, bu m��teri s�ras�n� y�neten bir kuyruk (queue) sistemi olu�turun. Program�n�z �u �zelliklere sahip olmal�d�r:

    Queue veri yap�s�n� bir array kullanarak tasarlay�n. Maksimum kapasitesini 10 m��teri ile s�n�rlay�n.
    Queue i�lemleri i�in a�a��daki fonksiyonlar� tan�mlay�n:
        enqueue: Kuyru�a yeni bir m��teri ekler. E�er kuyruk doluysa hata mesaj� verir.
        dequeue: Kuyruktan s�radaki m��teriyi ��kar�r ve �a��r�lan m��teri numaras�n� ekrana yazd�r�r. E�er kuyruk bo�sa hata mesaj� verir.
        isEmpty: Kuyru�un bo� olup olmad���n� kontrol eder.
        isFull: Kuyru�un dolu olup olmad���n� kontrol eder.
    Program, kullan�c�ya a�a��daki men�den se�im yapma imkan� vermelidir:

Men�:

1. Yeni m��teri ekle (Enqueue)
2. M��teriyi �a��r (Dequeue)
3. Kuyru�un bo� olup olmad���n� kontrol et (Is Empty)
4. Kuyru�un dolu olup olmad���n� kontrol et (Is Full)
5. ��k�� (Exit)

��kt� �rne�i:

1. Yeni m��teri ekle (Enqueue)
2. M��teriyi �a��r (Dequeue)
3. Kuyru�un bo� olup olmad���n� kontrol et (Is Empty)
4. Kuyru�un dolu olup olmad���n� kontrol et (Is Full)
5. ��k�� (Exit)
Se�iminizi yap�n: 1
Yeni m��teri numaras� girin: 101
M��teri 101 kuyru�a eklendi.

1. Yeni m��teri ekle (Enqueue)
2. M��teriyi �a��r (Dequeue)
3. Kuyru�un bo� olup olmad���n� kontrol et (Is Empty)
4. Kuyru�un dolu olup olmad���n� kontrol et (Is Full)
5. ��k�� (Exit)
Se�iminizi yap�n: 2
S�radaki m��teri �a�r�ld�: 101

...

Not: Program�n�z� dairesel bir kuyruk (circular queue) olarak tasarlayarak, kuyruk bo�alana kadar yeni m��teri ekleme ve ��karma i�lemlerini d�ng�sel bir yap�da ger�ekle�tirin.
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
				printf("\nYanl�s deger girdiniz.\n");	
		}
	
	}	
		
}









