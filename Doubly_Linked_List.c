//IMPLEMENTATION OF DOUBLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
	int data;
	struct NODE *left;
	struct NODE *right;
}node;

node *start=NULL;
int count=0;

void create();
void display();
void insert_front();
void delete_front();
void insert_end();
void delete_end();
void imp_double_queue();


int main()
{
	int choice;
	for(;;)
	{
		printf("\nMENU DRIVEN PROGRAM\n");
		printf("\n-----------------------------------------------------------------\n");
		printf("1)CREATE\n2)DISPLAY\n3)INSERT AT FRONT\n4)DELETE AT FRONT\n5)INSERT AT END\n6)DELETE AT END\n7)IMPLEMENTATION OF DOUBLE ENDED QUEUE\n8)EXIT\n");
		printf("\n-----------------------------------------------------------------\n");
		printf("\nENTER YOUR CHOICE:\t");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: create();

				break;

			case 2: display();

				break;

			case 3: insert_front();

				break;

			case 4: delete_front();

				break;

			case 5: insert_end();

				break;

			case 6: delete_end();

				break;

			case 7: imp_double_queue();

				break;

			default:printf("\nEXITING THE PROGRAM\n");
				exit(0);
		}
	}
	return 0;
}//END OF THE MAIN FUNCTION

void create()
{
	int i,n;
	int num;
	printf("\nENTER THE NUMBER OF EMPLOYEES:\t");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	       	insert_end();
	}
	
}//END OF THE CREATE FUNCTION

void insert_front()
{
	int num;
	node *ptr;
	node *temp;
	ptr=(node *)malloc(sizeof(node));
	printf("\nENTER THE DATA:\t");
	scanf("%d",&num);
	ptr->data=num;
	temp=start;
	start=ptr;
	temp->left=start;
	ptr->right=temp;
	ptr->left=NULL;
	
}//END OF THE INSERT AT FRONT FUNCTION

void delete_front()
{
	node *ptr;
	if(start==NULL)
		printf("\nCANNOT DELETE THE ELEMENTS\n");
	else
	{
		ptr=start;
		start=start->right;
		start->left=NULL;
		free(ptr);
	}
}//END OF DELETE AT FRONT FUNCTION

void insert_end()
{
	int num;
	node *ptr;	//FOR INSERTION OF NODE
	node *temp;	//FOR EACH NODE TRAVERSAL
	ptr=(node *)malloc(sizeof(node));
	printf("\nENTER THE DATA\t");
	scanf("%d",&num);
	ptr->data=num;
	
	ptr->left=NULL;
	ptr->right=NULL;

	if(start==NULL)
	{
		start=ptr;
	}
	else
	{
	temp=start;	
	while(temp->right!=NULL)
		temp=temp->right;
	temp->right=ptr;
	ptr->right=NULL;
	ptr->left=temp;
	}
	
}//END OF THE INSERT AT END FUNCTION

void delete_end()
{
	node *temp;
	node *prev;
	temp=start;
	while(temp->right!=NULL)
		temp=temp->right;
	prev=temp->left;
	prev->right=NULL;
	free(temp);
}//END OF THE DELETE AT END FUNCTION

void display()
{
	node *ptr;
	if(start==NULL)
	{
		printf("\nNO ELEMENTS TO DISPLAY\n");
	}
	else
	{
		printf("\n");
		ptr=start;
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->right;
		}
	}
}//END OF THE DISPLAY FUNCTION

void imp_double_queue()
{
	//IMPLEMENTATION OF DOUBLE ENDED QUEUE
	int choice;
	printf("\n1)INSERTION AT FRONT AND DELETION AT THE END\n2)INSERTION AT END AND DELETION AT FRONT\n");
	scanf("%d",&choice);
	int choice1,choice2;
	switch(choice)
	{
		case 1:printf("1)INSERT AT FRONT\n2)DELETE AT END\n");
		       scanf("%d",&choice1);
		       switch(choice1)
		       {
			       case 1: insert_front();

				       break;

			       case 2: delete_end();

				       break;

			       default: printf("\nINVALID CHOICE");
		       }

		       break;

		case 2:printf("1)INSERT\n2)DELETE\n");
		       scanf("%d",&choice2);
		       switch(choice2)
		       {
			       case 1: insert_end();

				       break;

			       case 2: delete_front();

				       break;

			       default: printf("\nINVALID CHOICE");
		       }

		       break;

		default: printf("\nINVALID CHOICE.PLEASE RE-ENTER\n");
	}
}//END OF THE DOUBLE ENDED QUEUE FUNCTION










	




