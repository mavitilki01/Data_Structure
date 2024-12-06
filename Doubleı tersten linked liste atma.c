#include <stdio.h>
#include <stdlib.h>



typedef struct doubled{
	int data1;
	struct doubled* next;
	struct doubled* prev;
}doubled;

typedef struct linked{
	int data2;
	struct linked* next;
}linked;



linked *traverse(doubled *d){
	
	if(d==NULL){
		return NULL;
	}
	doubled *dll=d;
	
	for(;dll->next!=NULL;)
		dll=dll->next;
		
		
	linked *head=NULL;
	linked *l=NULL;
	
	while(dll!=NULL){
		linked *temp=(linked*)malloc(sizeof(linked));
		temp->next=NULL;
		temp->data2= dll->data1;
		
		if(head==NULL){
			head=temp;
			l=temp;	
		}
		else{
			l->next=temp;
			l=temp;
			
		}
		dll=dll->prev;
	}
	return head;
}

void print(linked* l, doubled* d) {
    // Doubly linked list'i yazdýr
    printf("Doubly Linked List: ");
    while (d != NULL) {
        printf("%d ", d->data1);
        d = d->next;
    }
    printf("\n");

    // Single linked list'i yazdýr
    printf("Single Linked List: ");
    while (l != NULL) {
        printf("%d ", l->data2);
        l = l->next;
    }
    printf("\n");
}

// Doubled linked list oluþturma fonksiyonu
doubled* inil() {
    doubled* dll = (doubled*)malloc(sizeof(doubled));
    doubled* head = dll;
    int i;

    for (i = 0; i < 20; i++) {
        dll->data1 = i;
        if (i < 19) {
            dll->next = (doubled*)malloc(sizeof(doubled));
            dll->next->prev = dll;
            dll = dll->next;
        }
    }
    dll->next = NULL;  // Son düðümün next'i NULL
    return head;
}


int main(){
	int i;
	doubled *d=inil();
	linked *l= traverse(d);
	print(l,d);
	return 0;
}




