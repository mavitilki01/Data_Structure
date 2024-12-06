#include <stdio.h>
#include <stdlib.h>

typedef struct doubled {
    int data1;
    struct doubled* next;
    struct doubled* prev;
} doubled;

typedef struct linked {
    int data2;
    struct linked* next;
} linked;

// Doubly linked list'i tersten single linked list'e aktaran fonksiyon
linked* traverse(doubled* d) {
    if (d == NULL) {
        return NULL;
    }

    doubled* dll = d;

    // Listeyi sonuna kadar gez
    while (dll->next != NULL) {
        dll = dll->next;
    }

    linked* head = NULL;
    linked* l = NULL;

    // Doubly linked list'i tersten gezerek linked liste aktar
    while (dll != NULL) {
        linked* temp = (linked*)malloc(sizeof(linked));
        temp->data2 = dll->data1;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;  // �lk eleman
            l = temp;     // Listeyi y�neten i�aret�i
        } else {
            l->next = temp;  // Sonraki elemanlar� ekle
            l = temp;
        }

        dll = dll->prev;  // Tersten ilerle
    }

    return head;
}

// Listeyi yazd�ran fonksiyon
void print(linked* l, doubled* d) {
    // Doubly linked list'i yazd�r
    printf("Doubly Linked List: ");
    while (d != NULL) {
        printf("%d ", d->data1);
        d = d->next;
    }
    printf("\n");

    // Single linked list'i yazd�r
    printf("Single Linked List: ");
    while (l != NULL) {
        printf("%d ", l->data2);
        l = l->next;
    }
    printf("\n");
}

// Doubled linked list olu�turma fonksiyonu
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
    dll->next = NULL;  // Son d���m�n next'i NULL
    return head;
}

int main() {
    doubled* d = inil();  // Doubly linked list olu�tur
    linked* l = traverse(d);  // Doubly linked list'ten single linked list'e aktar
    print(l, d);  // Hem doubly linked list'i hem de single linked list'i yazd�r
    return 0;
}

