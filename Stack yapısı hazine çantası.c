#include <stdio.h>

/*
    Stack'iniz int tipinde de�erleri saklayabilmeli ve maksimum 10 eleman tutabilmelidir.
    Program, kullan�c�n�n �antaya yeni bir hazine eklemesini (push), en �stteki hazineyi ��karmas�n� (pop), �antan�n en �st�ndeki hazine par�as�na bakmas�n� (peek) ve �antan�n bo� olup olmad���n� kontrol etmesini (isEmpty) sa�lamal�d�r.
    Her ekleme (push) veya ��karma (pop) i�lemi sonras�nda ekrana, �antan�n durumu hakk�nda bilgi veren mesajlar yazd�r�lmal�d�r:
        Yeni bir hazine eklendi�inde, "Hazine par�as� �antaya eklendi: [de�er]" mesaj�n� g�sterin.
        �anta doldu�unda, "�anta dolu! Daha fazla hazine eklenemez." �eklinde bir hata mesaj� g�sterin.
        Bir hazine ��kar�ld���nda, "Hazine par�as� �antadan ��kar�ld�: [de�er]" mesaj�n� g�sterin.
        �anta bo�sa ve pop i�lemi yap�lmak istenirse, "�anta zaten bo�!" �eklinde bir uyar� g�sterin.
    Program, kullan�c�n�n a�a��daki men� arac�l���yla �anta i�lemlerini yapmas�na izin vermelidir:

Men�:
1. Yeni hazine ekle (Push)
2. Hazine ��kar (Pop)
3. En �stteki hazineye bak (Peek)
4. �antan�n bo� olup olmad���n� kontrol et (Is Empty)
5. ��k�� (Exit)

��kt� �rne�i:

1. Yeni hazine ekle (Push)
2. Hazine ��kar (Pop)
3. En �stteki hazineye bak (Peek)
4. �antan�n bo� olup olmad���n� kontrol et (Is Empty)
5. ��k�� (Exit)
Se�iminizi yap�n: 1
Bir hazine par�as� de�eri girin: 12
Hazine par�as� �antaya eklendi: 12

1. Yeni hazine ekle (Push)
2. Hazine ��kar (Pop)
3. En �stteki hazineye bak (Peek)
4. �antan�n bo� olup olmad���n� kontrol et (Is Empty)
5. ��k�� (Exit)
Se�iminizi yap�n: 3
En �stteki hazine par�as�: 12

1. Yeni hazine ekle (Push)
2. Hazine ��kar (Pop)
3. En �stteki hazineye bak (Peek)
4. �antan�n bo� olup olmad���n� kontrol et (Is Empty)
5. ��k�� (Exit)
Se�iminizi yap�n: 2
Hazine par�as� �antadan ��kar�ld�: 12
*/

#define SIZE 10

typedef struct {
	int bag[SIZE];
	int top;
}stack;

stack *node;


int push(int yeni){
	if(node->top== SIZE-1){
		printf("\nCanta dolu! Daha fazla hazine eklenemez.\n");
	}
	else{
		node->top++;
		node->bag[node->top]=yeni;
		printf("\nHazine parcasi cantaya eklendi: %d", node->bag[node->top]);
		}
	printf("\nCantada toplam %d tane eleman var.\n", (node->top)+1);
	return node->top;
	}
	
int pop(){
	if(node->top==-1){
		printf("\nCanta zaten bos!\n");
		return node->top;
	}
	printf("\nHazine parcasi cantadan cikarildi: %d\n", node->bag[node->top]);
	node->top--;
	return node->top;
}

void peek(){
	if(node->top==-1){
		printf("\nCanta zaten bos!\n");
	}
	else
		printf("\n En ustteki top degeri: %d\n", node->bag[node->top]);
}

void isEmpty(){
	if(node->top==-1)
		printf("\nCanta bos\n");
	else
		printf("\nCantada %d tane eleman var.\n", (node->top)+1); 
}



int main(){
	
	node =(stack *)malloc(sizeof(stack));
	node->top=-1;
	while(1){
		printf("\n 1. Yeni hazine ekle (Push)\n 2. Hazine cikar (Pop)\n 3. En ustteki hazineye bak (Peek)\n 4. Cantanin bos olup olmadigini kontrol et (Is Empty)\n 5. Cikis (Exit)\n");
		int choose;
		printf("Seciminizi yapiniz: ");
		scanf("%d", &choose);
		
		switch(choose){
			case 1:
				printf("\nBir hazine parcasi degeri girin: ");
				int data;
				scanf("%d", &data);
				push(data);
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				isEmpty();
				break;
			case 5:
				exit(1);
			default:
				printf("\nYanlis bir deger girdin!\n");
				break;
			
		}
	}
	
}









