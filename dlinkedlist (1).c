#include<stdio.h>
#include <stdlib.h>
struct node 
{
int data ;
struct node *next;
struct node *prev;
};

void traverse(struct node *head)
{
	if (head == NULL) {
		printf("\nList is empty\n");
		return;
	}
	
	struct node* temp;
	temp = head;
	while (temp != NULL)
        {
		printf("Data = %d\n", temp->data);
		temp = temp->next;
	}
}

void revtraverse(struct node *head)
{        
	if (head == NULL) {
		printf("\nList is empty\n");
		return;
	}
	
	struct node* temp;
	temp = head;
	while (temp->next != NULL)
        {
		temp = temp->next;
	}
  
       while (temp->prev != NULL)
        {
		printf("Data = %d\n", temp->data);
		temp = temp->prev;
	}
	printf("Data = %d\n", temp->data);

}

struct node* addtoempty(struct node* head,int data)
{
	
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->data = data;
        temp->next = NULL;
        head=temp;
        return head;
}

struct node* addatend(struct node*  head)
{       int data;
	struct node *temp, *tp;
	temp = malloc(sizeof(struct node));
	temp->prev = NULL;
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temp->data = data;
	temp->next = NULL;
	tp = head;
	if (head == NULL) {

		head = temp;
	}
	else {
		while (tp->next != NULL)
			tp = tp->next;
                        tp->next = temp;		
			temp->prev = tp;
			return head;
	      }
}

struct node* createlist(struct node* head)
{
int n ,data,i;
printf("enter the no of nodes : ");
scanf("%d",&n);
if(n==0)
return head;
printf(" For node 1 \n Enter number to be inserted: ");
scanf("%d",&data);
head = addtoempty(head,data);
for(i=1;i<n;i++)
{
printf("For node %d ",i+1);
head = addatend(head);
}
return head;
}



struct node* insertatfront(struct node *head)
{
	int data;
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	printf("\n ");
	temp->data = data;
	temp->prev = NULL;
	temp->next = head;
	head = temp;
	return head;
}




struct node* insertatposition(struct node* head)
{
	int data, pos, i = 1;
	struct node *temp, *newnode;
	newnode = malloc(sizeof(struct node));
	newnode->next = NULL;
	newnode->prev = NULL;

	printf("\nEnter position : ");
	scanf("%d", &pos);
	

	
	if (head == NULL) {
		head = newnode;
		newnode->prev = NULL;
		newnode->next = NULL;
	}

	else if (pos == 1) {
	
	insertatfront(head);
	}
	else {
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	newnode->data = data;
	temp = head;
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next = newnode;
		temp->next->prev = newnode;
	}
return head;
}

struct node* deletefirst(struct node* head)
{
	struct node* temp;
	if (head == NULL)
		printf("\nList is empty\n");
	else {
		temp = head;
		head = head->next;
		if (head!= NULL)
			head->prev = NULL;
		free(temp);
	}
return head;
}


struct node* deleteend(struct node* head)
{
	struct node* temp;
	if (head == NULL)
		printf("\nList is empty\n");
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	if (head->next == NULL)
		head= NULL;
	else {
		temp->prev->next = NULL;
		free(temp);
	}
return head;
}
struct node* deleteposition(struct node* head)
{
	int pos, i = 1;
	struct node *temp, *position;
	temp = head;

	if (head == NULL)
		printf("\nList is empty\n");

	else {

		printf("\nEnter position : ");
		scanf("%d", &pos);


		if (pos == 1) {
			deletefirst(head); 
			if (head!= NULL) {
				head->prev = NULL;
			}
			free(position);
			return head;
		}

	
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
	
		position = temp->next;
		if (position->next != NULL)
			position->next->prev = temp;
		temp->next = position->next;

	
		free(position);
	}
        return head;
}


int main()
{
        struct node *head= NULL;
	int choice;
	while (1) {

		printf("\n\t1 To Traverse list\n");
		printf("\t2 To Reverse Traverse list\n");
                printf("\t3  to create a linked list and add element\n");
		printf("\t4 For insertion at"
			" starting\n");
		printf("\t5 For insertion at end\n");
		printf("\t6 For insertion at any position\n");
		printf("\t7 For deletion of first element\n");
		printf("\t8 For deletion of last element\n");
		printf("\t9 For deletion of element at any position\n");
		printf("\t0 To exit\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice) 
               {
		case 1:
			traverse(head);
			break;
		case 2:
                        revtraverse(head);
			break;
                case 3:
        		head = createlist(head);
			break;
		case 4:
			head= insertatfront(head);  
			break;
		case 5:
			head =addatend(head);
			break;
		case 6:
			head =insertatposition(head);
			break;
		case 7:
			head =deletefirst(head);
			break;
		case 8:
			head=deleteend(head);
			break;
		case 9:
			head=deleteposition(head);
			break;

		case 0:
			exit(1);
			break;
		default:
			printf("Incorrect Choice. Try Again \n");
			continue;
	 	}
	}

	return 0;
}
