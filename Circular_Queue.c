//IMPLEMENTATION OF CIRCULAR QUEUE

#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int front=-1;
int rear =-1;
int q[MAX];
void insert(int q[],int ele);
int delete(int q[]);
void display(int q[]);


int main()
{
	int i,ele;
	int a[MAX];
	int choice,del;

	for(;;)
	{
		printf("\nMENU DRIVEN PROGRAM\n");
		printf("\n----------------------------------------------------------------------\n");
		printf("1)INSERT AN ELEMENT\n2)DELETE AN ELEMENT\n3)DISPLAY THE STATUS OF THE QUEUE\n4)EXIT\n")	;
		printf("\n----------------------------------------------------------------------\n");
		printf("Enter your choice:\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\nENTER NEW ELEMENT=\t");
			       scanf("%d",&ele);
			       insert(a,ele);
			       
			       break;

			case 2:del=delete(a);
			       printf("\nDELETED ELEMENT=%d",del);

			       break;

			case 3:printf("\nDISPLAYING THE ELEMENTS OF CIRCULAR QUEUE\n");
			       display(a);

			       break;

			default:printf("EXITING THE PROGRAM\n");
				exit(0);

				break;

		}
	}

	return 0;
}	

void insert(int q[],int ele)
{
	printf("REAR=%d\n",rear);
	if(front==-1&&rear==-1)
	{
		front++;
		rear++;
	}
	if(rear==(MAX-1) && front!=0)
	{
		rear=0;
//		printf("HELLO CIRCULAR QUEUE!!\n");
	}

	if(rear>=front)
	{	
		if(rear-front==(MAX))
		{printf("QUEUE OVERFLOW !!\n"); return;}
		else
		{
			q[rear++]=ele;
		}
	}
	if(rear<front)
	{
		if(front=rear)
		{	printf("QUEUE OVERFLOW!!\n");
			return;
		}

		else
			q[rear++]=ele;
	}
}

int delete(int q[])
{
	int val;
	printf("FRONT=%d\n",front);
	if(front==-1 && rear==-1)
	{
		printf("QUEUE UNDERFLOW !!\n");
		return -1;
	}
	else
	{
		val=q[front];
		front=(front+1)%MAX;
		return val;
	}
}

void display(int q[])
{
	int i;
	if(rear>=front)
	{
		for(i=front;i<rear;i++)
		{
			printf("%d\t",q[i]);
		}
	}
	if(front>rear)
	{
		for(i=0;i<=rear;i++)
		{
			printf("%d\t",q[i]);
		}
		for(i=front;i<(MAX-1);i++)
		{
			printf("%d\t",q[i]);
		}
	}
	printf("\n");
}

