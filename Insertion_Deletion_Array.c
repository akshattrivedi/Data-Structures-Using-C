//PROGRAM TO INSERT OR DELETE AN ELEMENT FROM THE ARRAY

#include<stdio.h>
#include<stdlib.h>
void display(int arr[], int n);
void delete(int arr[],int position,int n);
void insert(int arr[],int position,int element,int n);

int main()
{
	int n;
	int i;
	int pos,ele;
	int pos1;
	printf("\nEnter the size of the array\n");
	scanf("%d",&n);
	int a[100];
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	for(;;)
	{
		int choice;
		printf("\n---------------\n");
		printf("1. Display \n2. Insert an element into the array \n3. Delete an element from the array \n4. Exit \n");

		printf ("\n>>>>>>>>>");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{
			case 1: display(a,n);

				break;

			case 2:// int pos, ele;
				printf("Enter the position for which you want to enter the element\n");
				scanf("%d",&pos);
				printf("Enter any element\n");
				scanf("%d",&ele);
				insert(a,pos,ele,n);
				n=n+1;

				break;

			case 3:// int pos1;
				printf("Enter the postion for which you want to delete an element\n");
				scanf("%d",&pos1);
				delete(a,pos1,n);
				n=n-1;

				break;

			default: exit(0);

		}
	}
	return 0;
}// END OF THE MAIN FUNCTION

void insert(int arr[],int position,int element,int n)
{
	int i,j,ap;	//ap=actual position
	ap=position-1;

	for(i=n;i>ap;i--)
			arr[i]=arr[i-1];

	arr[ap]=element;
//	n=n+1;
}// END OF THE INSERT FUNCTION

void delete(int  arr[],int position,int n)
{
	int ap;
	ap=position-2;
	int i;
	for(i=(ap+1);i<n;i++)
		arr[i]=arr[i+1];

//	n=n-1;
} // END OF THE DELETE FUNCTION

void display(int arr[], int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
} //END OF THE DISPLAY FUNCTION




			
