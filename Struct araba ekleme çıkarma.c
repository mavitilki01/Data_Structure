#include <stdio.h>

struct car {
char model[50];
int year;
struct car *prev;
struct car *next;
};

void AddSorted (struct car **head, char model[], int year);

void main(){
	struct car *head =(struct car*)malloc(sizeof(struct car));
	
	
	AddSorted(&head,"Toyota",2021);
	AddSorted(&head,"Auris",2018);
	AddSorted(&head,"BMW",2013);
	AddSorted(&head,"Volswagen",1945);
	AddSorted(&head,"Leon",2024);

	printf("%s", head->model);
	printf("%d", head->year);

}

void AddSorted (struct car **head, char model[], int year){
	struct car *temp =(struct car*)malloc(sizeof(struct car));
	strcpy(temp->model=model);
	temp->year=year;
	temp->next=NULL;
	temp->prev=NULL;		
	
	if(*head==NULL){
		*head=temp;
		return *head;
	}

	while(*head!=NULL){					// büyükten küçüðe sýralýyoruz
		if((*head)->year < temp->year){
			(*head)->prev->next=temp;
			temp->prev=(*head)->prev;
			temp->next=head;
			(*head)->prev=temp;
			return *head;	
	}
		else{
		head=(*head)->next;
				
	}
	
	}

	(*head)->prev->next=temp;
	temp->prev=(*head)->prev;
	temp->next=NULL;
	
	return *head;
	}

	


