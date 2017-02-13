//PROGRAM TO EVALUATE POSTFIX EXPRESSION

#include<stdio.h>
#include<ctype.h>
#define MAX 50
int top=-1;
int stk[MAX];
void push(int stk[],int ele);
int pop(int stk[]);
int evaluate(char postfix[]);



int main()
{
	char postfix[MAX];
	int final_value=0;
	printf("\nENTER A POSTFIX EXPRESSION\n");
	scanf("%s",postfix);
	final_value=evaluate(postfix);
	printf("FINAL EVALUATION OF THE POSTFIX EXPRESSION=\t%d\n",final_value);
	return 0;
}


void push(int stk[],int ele)
{
	if(top>=MAX)
		printf("\nSTACK OVERFLOW!!\n");
	else
		stk[++top]=ele;
}

int pop(int stk[])
{
	if(top==-1)
		printf("\nSTACK UNDERFLOW!!\n");
	else
		return(stk[top--]);
}

int evaluate(char postfix[])
{
	int op1,op2,i,temp,fval;
//	printf("\nPOSTFIX TRAVERSE\tSTACK\n");
	for(i=0;postfix[i]!='\0';i++)
	{
		if(isdigit(postfix[i]))
		{
//			printf("\ndigit[%d]=\t%c",i,postfix[i]);
			push(stk,postfix[i]-48);
//			printf("\tstk[%d]=\t%d",top,stk[top]);

		}
		else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='^' || postfix[i]=='%')
		{
			op1=pop(stk);
			op2=pop(stk);
			if	(postfix[i]=='+')
				temp = op2 + op1;
			else if	(postfix[i]=='-')
				temp = op2 - op1;
			else if	(postfix[i]=='*')
				temp = op2 * op1;
			else if	(postfix[i]=='/')
				temp = op2 / op1;
			else if (postfix[i]=='^')
				temp = op2 ^ op1;
			else if	(postfix[i]=='%')
				temp = op2 % op1;
			
//			printf("\noperator[%d]=\t%c",i,postfix[i]);
			push(stk,temp);
//			printf("\tstk[%d]=\t%d",top,stk[top]);
		}
		else
		{
			printf("\nINVALID EXPRESSION\n");
		}
	}
/*	printf("\nTOP VALUE=%d\n",top);
	printf("\nSTACK ELEMENTS\n");
	for(i=0;i<=top;i++)
		printf("\n[%d]=\t%d",i,stk[i]);
	printf("\n");
*/
	fval=pop(stk);

	return fval;
}
