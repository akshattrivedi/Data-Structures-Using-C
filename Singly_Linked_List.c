//IMPLEMENTATION OF SINGLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NODE{
	int data;
//	char USN[20];
//	char name[20];
///	char branch[20];
//	int sem;
//	int ph_no;
	struct NODE *link;
	}node;

node *start=NULL;

void create();
void display();
void insert_front();
void delete_front();
void insert_end();
void delete_end();
void imp_stack();

int main()
{
	int choice;

	for(;;)
	{
		printf("\nMENU DRIVEN PROGRAM\n");
		printf("\n--------------------------------------------------------------------\n");
		printf("1)CREATE\n2)DISPLAY\n3)INSERT AT FRONT\n4)DELETE AT FRONT\n5)INSERT AT END\n6)DELETE AT END\n7)IMPLEMENTATION OF STACK\n8)EXIT\n");
		printf("\n--------------------------------------------------------------------\n");
		printf("\nEnter your choice:\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:create();

			       break;

			case 2:display();

			       break;

			case 3:insert_front();

			       break;

			case 4:delete_front();

			       break;

			case 5:insert_end();

			       break;

			case 6:delete_end();

			       break;

			case 7:imp_stack();
			       
			       break;





			default:printf("\n");
			       	exit(0);
		}
				
	}
	return 0;
}

void create()
{
	int i,n;
	printf("\nENTER NUMBER OF STUDENTS:\t");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	insert_front();
	}
}//END OF THE CREATE FUNCTION

void display()
{
	
	node *dstart;
	dstart=start;
	if(dstart==NULL)
		printf("\nNo elements ");
	else
	{
		while(dstart!=NULL)
		{
		printf("%d\n",dstart->data);
		dstart=dstart->link;
		}
	}
}

void insert_front()
{
	node *ptr;
	int num;
	ptr=(node *)malloc(sizeof(node));
	printf("\nENTER THE DATA\t");
	scanf("%d",&num);
	ptr->data=num;
	ptr->link=start;
	start=ptr;
}

void delete_front()
{
	node *ptr;
	ptr=start;
	start=ptr->link;
	free(ptr);
}

void insert_end()
{
	int num;
	node *ptr;
	node *temp;
	temp=start;
	ptr=(node *)malloc(sizeof(node));
	printf("\nENTER THE DATA=\t");
	scanf("%d",&num);
	ptr->data=num;
	ptr->link=NULL;
	while(temp->link!=NULL)
		temp=temp->link;
	temp->link=ptr;
}

void delete_end()
{
	node *ptr;
	node *prev;
	ptr=start;
	while(ptr->link!=NULL)
	{
		prev=ptr;
		ptr=ptr->link;
	}
	prev->link=NULL;
	free(ptr);
}

void imp_stack()
{
	int choice;
	printf("\n1)PUSH\n2)POP\n3)DISPLAY\n");
	printf("\nENTER YOUR CHOICE\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: insert_front();
			break;
		case 2: delete_front();
			break;
		case 3: display();
			break;
		default:
			printf("\nINVALID CHOICE\n");
	}
}
	
