#include <stdio.h>

/*
    Stack'iniz int tipinde deðerleri saklayabilmeli ve maksimum 10 eleman tutabilmelidir.
    Program, kullanýcýnýn çantaya yeni bir hazine eklemesini (push), en üstteki hazineyi çýkarmasýný (pop), çantanýn en üstündeki hazine parçasýna bakmasýný (peek) ve çantanýn boþ olup olmadýðýný kontrol etmesini (isEmpty) saðlamalýdýr.
    Her ekleme (push) veya çýkarma (pop) iþlemi sonrasýnda ekrana, çantanýn durumu hakkýnda bilgi veren mesajlar yazdýrýlmalýdýr:
        Yeni bir hazine eklendiðinde, "Hazine parçasý çantaya eklendi: [deðer]" mesajýný gösterin.
        Çanta dolduðunda, "Çanta dolu! Daha fazla hazine eklenemez." þeklinde bir hata mesajý gösterin.
        Bir hazine çýkarýldýðýnda, "Hazine parçasý çantadan çýkarýldý: [deðer]" mesajýný gösterin.
        Çanta boþsa ve pop iþlemi yapýlmak istenirse, "Çanta zaten boþ!" þeklinde bir uyarý gösterin.
    Program, kullanýcýnýn aþaðýdaki menü aracýlýðýyla çanta iþlemlerini yapmasýna izin vermelidir:

Menü:
1. Yeni hazine ekle (Push)
2. Hazine çýkar (Pop)
3. En üstteki hazineye bak (Peek)
4. Çantanýn boþ olup olmadýðýný kontrol et (Is Empty)
5. Çýkýþ (Exit)

Çýktý Örneði:

1. Yeni hazine ekle (Push)
2. Hazine çýkar (Pop)
3. En üstteki hazineye bak (Peek)
4. Çantanýn boþ olup olmadýðýný kontrol et (Is Empty)
5. Çýkýþ (Exit)
Seçiminizi yapýn: 1
Bir hazine parçasý deðeri girin: 12
Hazine parçasý çantaya eklendi: 12

1. Yeni hazine ekle (Push)
2. Hazine çýkar (Pop)
3. En üstteki hazineye bak (Peek)
4. Çantanýn boþ olup olmadýðýný kontrol et (Is Empty)
5. Çýkýþ (Exit)
Seçiminizi yapýn: 3
En üstteki hazine parçasý: 12

1. Yeni hazine ekle (Push)
2. Hazine çýkar (Pop)
3. En üstteki hazineye bak (Peek)
4. Çantanýn boþ olup olmadýðýný kontrol et (Is Empty)
5. Çýkýþ (Exit)
Seçiminizi yapýn: 2
Hazine parçasý çantadan çýkarýldý: 12
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









