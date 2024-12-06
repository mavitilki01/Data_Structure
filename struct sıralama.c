#include<stdio.h>
#include<stdlib.h>
/***************************************************************************************************************/
/* STRUCTURE DEFINITION */

struct node {

	int data;
	struct node * next; };


/* The function removes duplicates from a sorted list */

struct node * removeDuplicates(struct node* head){
	
  /* Pointer to traverse the linked list */
  struct node* current = head;

  /* Pointer to store the next pointer of a node to be deleted*/
  struct node* temp;

  /* do nothing if the list is empty */
  if(current == NULL)
     return;

  /* Traverse the list till last node */
  while(current->next != NULL)
  {
   /* Compare current node with next node */
    if(current->data == current->next->data)
    {
       /*The sequence of steps is important*/
      temp = current->next;
      current->next=temp->next;
      free(temp);
    }
    else /* This is tricky: only advance if no deletion */
    {
      current = current->next;
    }
  }
  return head;
}
struct node * create_list2(void){
	struct node * head=NULL; struct node * tmp;
 	int tt=0;
	printf(" \nenter value for the list(-1 to exit) : ");
	for(scanf("%d",&tt);tt!=-1; scanf("%d",&tt)){
			if(head==NULL){
			    head= (struct node *) malloc( sizeof(struct node));
				head->data=tt;
				head->next =NULL;
            }
            else{
                tmp= (struct node *) malloc( sizeof(struct node));
                tmp->data=tt;
				tmp->next =head;
				head=tmp;
            }
	}
	return head;
 }

/***************************************************************************************************************/
/* DELETE THE NODE THAT HAS SOME VALUE GIVEN AS INPUT PARAMETER */
/***************************************************************************************************************/

struct node * delete_node(struct  node * head, int  d)  {

	struct node * q=NULL, *p=NULL;
	if(head==NULL)
        printf( "NULL list");
	else{
		
	    for(p=head; p!=NULL && p->data!=d;p=p->next)
	      q=p;

		if(p!=NULL) 						// if d is found
			if(p==head)	{ 	 		// if d is found in head node
						head = head->next;
						free(p); }
			else 		{ q->next=q->next->next; 	// or q->next=p->next
					  free(p); }			/* d is found in node p in list and
									   q is the previous node in list */
	}

	return head;
}
/*
	IMPORTANT NOTE :::
	FUNCTION HAS TO RETURN head BACK BECAUSE d CAN BE FOUND ALSO IN head NODE.
	SO head MAY BE DELETED AND NEXT NODE MAY BE THE NEW HEAD 	*/


/***************************************************************************************************************/
/* DISPLAY THE LIST */
/***************************************************************************************************************/
void display_list(struct  node * head)
{
	struct node * p;

	if( head!=NULL){
	    for( p=head; p!=NULL;p=p->next)
            printf("%d	", p->data);
		printf("\n");
    }
}

/***************************************************************************************************************/
/* FIND MAX DATA IN THE LIST */
/***************************************************************************************************************/
int maximum(struct  node * head)
{
		struct node *p;
		int max=head->data;

		for( p=head; p!=NULL;p=p->next)
			if(max<p->data) max=p->data;

		return max;

}


/***************************************************************************************************************/
/* APPEND SOME DATA TO THE HEAD */
/***************************************************************************************************************/
struct node * append_node(struct node *head,int data)
{
	struct node  * tmp= (struct node*)malloc( sizeof(struct node));
	tmp->data=data;
	tmp->next=NULL;


	if(head==NULL)  { head=tmp;}
	else 	{ tmp->next=head; head=tmp;}

	return head;
}
/***************************************************************************************************************/



/***************************************************************************************************************/
/* SORT LINKED LIST */
/***************************************************************************************************************/
struct node *  sort (struct  node * head)
{
	int cnt=0, i=0,k;
	struct node * p ; struct node * sorted=NULL;
	int max;
		while(head!=NULL)
	{		max=maximum(head);// FIND MAXIMUM VALUE

			head=delete_node(head, max);	// DELETE NODE WITH MAX DATA IN UNSORTED LIST

			sorted=append_node(sorted,max); // ADD MAX VALUE TO SORTED LIST

	}
return sorted;
}

/***************************************************************************************************************/
/* SAMPLE MAIN() */
/***************************************************************************************************************/
main()
{ 	int i,v;
 	struct node * head = NULL;
 	struct node * head2 = NULL;
 	struct node * head3 = NULL;
/*
	for(i=0;i<6;i++)
		{	printf(" \nenter value for first list : ");
			scanf("%d", &v);
			create_list1(&head,v);	}
	display_list(head);


*/
	head=NULL;
	head=create_list2();
	display_list(head);
	head2=removeDuplicates(head);
	display_list(head2);
	head3=sort(head2);
	display_list(head3);
	/*
	printf(" enter some value to delete ");
	scanf("%d", &v);
	head= delete_node(head,v);
	//display_list(head);
*/
}

/***************************************************************************************************************/
