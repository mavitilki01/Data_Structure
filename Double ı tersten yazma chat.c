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
            head = temp;  // Ýlk eleman
            l = temp;     // Listeyi yöneten iþaretçi
        } else {
            l->next = temp;  // Sonraki elemanlarý ekle
            l = temp;
        }

        dll = dll->prev;  // Tersten ilerle
    }

    return head;
}

// Listeyi yazdýran fonksiyon
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

int main() {
    doubled* d = inil();  // Doubly linked list oluþtur
    linked* l = traverse(d);  // Doubly linked list'ten single linked list'e aktar
    print(l, d);  // Hem doubly linked list'i hem de single linked list'i yazdýr
    return 0;
}

