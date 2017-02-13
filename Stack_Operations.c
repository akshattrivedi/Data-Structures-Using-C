// PROGRAM TO IMPLEMENT OPERTAIONS ON STACK TO PUSH AND POP THE ELEMENTS

#include<stdio.h>
#include<stdlib.h>

int top=-1;
#define MAX 10

void push(int *a,int ele);
void pop(int *a);
void display(int *a);
void palindrome(int *a);



int main()
{
	int choice,ele;
	int arr[MAX];
	while(1)
	{
		printf("\nMENU DRIVEN PROGRAM\n");
		printf("---------------------------------------------------------------\n");
		printf("1.PUSH AN ELEMENT INTO THE STACK\n2.DELETE AN ELEMENT FROM THE STACK\n3.CHECK FOR PALINDROME\n4.STATUS OF THE STACK\n5.EXIT\n");
		printf("---------------------------------------------------------------\n");
	        printf(">>>>");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter any new element\n");
				scanf("%d",&ele);
				push(arr,ele);

				break;

			case 2: pop(arr);
				
				break;

			case 3: palindrome(arr);

				break;

			case 4: display(arr);

				break;

			default: exit(0);

		}
	}
	return 0;
} //END OF THE MAIN FUNCTION

void push(int *a,int ele)
{
	if(top>=(MAX-1))
	{	printf("STACK OVERFLOW !!!\n");
	//	return 0;
	}
		
	else
	{
		++top;
		a[top]=ele;
	//	return a[top];
	}
}//END OF THE PUSH FUNCTION

void pop(int *a)
{
	if(top==-1)
		printf("STACK UNDERFLOW !!!\n");
	else
		--top;
}//END OF THE POP FUNCTION

void display(int *a)
{
	int i;
	for(i=0;i<=top;i++)
	{
		printf("%d\t",a[i]);
	
	}
}//END OF THE DISPLAY FUNCTION

void palindrome(int *a)
{
	int temp, n;
	int i,rev,digits;
	printf("\nENTER THE NUMBER THAT HAS TO BE CHECKED FOR THE PALINDROME\n");
	scanf("%d",&n);
	temp=n;
	while(top!=-1)
	{
		pop(a);
	}

	while(n!=0)
	{
		rev=n%10;
		push(a,rev);
		n=n/10;
		++digits;
	}

	if(digits%2==0)
	{
		for(i=0;i<(digits/2);i++)
		{
			if(a[i]!=a[digits-i-1])
			{
				printf("It is not a palindrome\n");
				return ;
			}
			else
				printf("It is a palindrome number\n");

		}
	}
	else
	{
		for(i=0;i< ( (digits-1 ) / 2);i++)
		{
			if(a[i]!=a[digits-i-1])
			{
				printf("It is not a palindrome\n");
				return;
			}
			else
			{
				printf("It is a palindrome number\n");
				return;
			}

		}
	}
}// END OF THE PALINDROME FUNCTION





		



				







