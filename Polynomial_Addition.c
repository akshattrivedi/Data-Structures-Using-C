//IMPLEMENTATION OF SINGLY CIRCULAR LINKED LIST USING POLYNOMIAL ADDITION

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct NODE
{
	int coeff;
	int exp;
	struct NODE *link;
}node;

node *create();
node *insert(node *,int,int);
void display(node *);
void evaluate(node *);
node *add(node *,node *);


int main()
{
	int choice;
	node *p1=NULL,*p2=NULL,*p3=NULL;
	
	for(;;)
	{
		printf("\nMENU DRIVEN PROGRAM\n");
		printf("\n-----------------------------------------------------\n");
		printf("1)ADD\n2)EVALUATE\n3)EXIT\n");
		printf("\n-----------------------------------------------------\n");
		printf("\nENTER YOUR CHOICE\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: p1=create();
				display(p1);
				p2=create();
				display(p2);
				p3=add(p1,p2);
				display(p3);

				break;

			case 2: p1=create();
				display(p1);
				evaluate(p1);

				break;

			case 3: printf("\nEXITING THE PROGRAM\t");
				exit(0);

				break;
		
			default: printf("\nINVALID CHOICE.PLEASE RE-ENTER\n");
		}
	}
	return 0;
}//END OF THE MAIN FUNCTION

node *create()
{
	int num,i;	
	int coeff,exp;
	node *dstart;
	dstart=NULL;
	printf("\nENTER THE NUMBER OF POLYNOMIALS\t");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("\nENTER THE COEFFICENT AND ITS EXPONENETS\t");
		scanf("%d%d",&coeff,&exp);
		dstart=insert(dstart,coeff,exp);
		printf("\n");
	}
	return(dstart);
}//END OF THE CREATE FUNCTION

node *insert(node *start,int coeff,int exp)
{
	node *ptr;
	node *temp;
	node *temp1;
	ptr=(node *)malloc(sizeof(node));
	if(start==NULL)
	{
		start=ptr;
		ptr->coeff=coeff;
		ptr->exp=exp;
		ptr->link=start;
		return(start);
	}
	else
	{
		ptr->coeff=coeff;
		ptr->exp=exp;
		ptr->link=start;
		temp=start;
		temp1=start;
		while(temp->link=start);
		{
			temp1=temp;
			temp=temp->link;
		}
		temp1->link=ptr;
		return(start);
	}
}//END OF THE INSERT FUNCTION

void display(node *p)
{
	node *ptr;
	node *start;
	start=p;
	if(start==NULL)
		printf("\nNO ELEMENTS TO DISPLAY\n");
	else
	{
		ptr=start;
		while(ptr->link!=start)
		{
			printf("%dx^%d+",ptr->coeff,ptr->exp);
			ptr=ptr->link;
		}
		printf("%dx^%d",ptr->coeff,ptr->exp);
		printf("\n");
	}
}//END OF THE DISPLAY FUNCTION

void evaluate(node *p)
{
	int x,eval=0;
	node *temp;
	temp=p;
	printf("\nENTER THE VALUE OF X=\t");
	scanf("%d",&x);
	while(temp->link!=p)
	{
		eval=eval+((temp->coeff)*(pow(x,temp->exp)));
		temp=temp->link;
	}
	eval=eval+((temp->coeff)*(pow(x,temp->exp)));
	printf("\nTHE FINAL EVALUATION OF THE POLYNOMIAL=\t%d",eval);
}//END OF THE EVALUATE FUNCTION

node *add(node *p1,node *p2)
{
	node *start1;
	node *start2;
	start1=p1;
	start2=p2;
	node *p3=NULL;
	while(p1->link!=start1)
		p3=insert(p3,p1->coeff,p1->exp);
	p3=insert(p3,p1->coeff,p1->exp);

	while(p2->link!=start2)
		p3=insert(p3,p2->coeff,p2->exp);
	p3=insert(p3,p2->coeff,p2->exp);
}//END OF THE ADD FUNCTION


		
	








