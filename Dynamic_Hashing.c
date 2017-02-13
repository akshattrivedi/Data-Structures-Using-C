//DYNAMIC HASHING

#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
	int data;
	int key;
}node;
node *a[15];
int count=0;

void insert(int,int);
void display();


int main()
{
	FILE *fp;
	int emp,key;
	fp=fopen("emp.txt","r");
	printf("\nENTRY OF DATA USING FILE\n");
	while(fscanf(fp,"%d",&emp)!=EOF)
	{	
		key=emp%100;
		if(count==15)
		{
			printf("HASH TABLE IS FULL\n");
			exit(0);
		}
		insert(key,emp);
	}
	display();
	fclose(fp);
	
}//END OF THE MAIN FUNCTION

void insert(int key,int emp)
{
	int k;
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=emp;
	temp->key=key;
	k=key%10;
	while(a[k]!=NULL)
	{
		printf("\nCOLLISION DETECTED AT %d\n",k);
		k++;
		k=k%15;
		printf("\nAVOIDING COLLISION BY SOLVING THIS BY LINEAR PROBING\n");

	}
	a[k]=temp;
	++count;
}//END OF THE INSERT FUNCTION

void display()
{
	int i;
	printf("\n\tKEY\tDATA\n");
	for(i=0;i<15;i++)
	{
		if(a[i]==NULL)
		{
			printf("%d.\t-1\n",i);
		}
		else
		{
			printf("%d.\t%d\t%d\n",i,a[i]->key,a[i]->data);
		}
	}
}//END OF THE DISPLAY FUNCTION


