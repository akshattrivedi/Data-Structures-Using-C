//CONVERSION OF AN EXPRESSION FROM INFIX TO POSTFIX

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100
int top=-1;
char stk[MAX];

void push(char stk[],char val);
char pop(char stk[]);
void infix_to_postfix(char infix[],char postfix[]);
int priority(char opt);

int main()
	{
		char infix[MAX],postfix[MAX],len_inf,i,j=0;
		printf("\nENTER AN INFIX EXPRESSION\n");
		scanf("%s",infix);
		for(i=0;i<infix[i]!='\0';i++)
			if(infix[i]!='(' && infix[i]!=')')
				j++;
		strcpy(postfix,"");
		infix_to_postfix(infix,postfix);
		printf("\nTHE POSTFIX EXPRESSION WILL BE \n");
		for(i=0;i<j;i++)
			printf("%c",postfix[i]);
		printf("\n\n");
		return 0;
	}

void push(char stk[],char val)
	{
		if(top>=MAX)
		{	printf("\nSTACK OVERFLOW !!\n");
			return;
		}
			
		else
			stk[++top]=val;
	}

char pop(char stk[])
	{
		if(top==-1)
			printf("\nSTACK UNDERFLOW !!\n");
		else
			return(stk[top--]);
	}

int priority(char opt)
	{
		if(opt=='*'||opt=='/'||opt=='%')
			return 1;
		else if(opt=='+'||opt=='-')
			return 0;
	}

void infix_to_postfix(char infix[],char postfix[])
	{
		int i=0,j=0,k=0;
		char temp;
		strcpy(postfix,"");
		push(stk,'(');
		for(i=0;i<MAX;i++)
		{
			if(infix[i]=='\0')
			{
				infix[i]=')';
				infix[i+1]='\0';
				break;
			}
		}

		for(i=0;infix[i]!='\0';i++)
		{
			if(infix[i]=='(')
			{
				push(stk,infix[i]);
			}
			
			else if(infix[i]==')')
			{
				while( (top!=-1) && (stk[top]!='(') )
				{
					postfix[k]=pop(stk);
//					printf("infix( ')' )=%c\t%d\n",postfix[k],k);
					k++;
				}
				if(top==-1)
				{
					printf("EXPRESSION IS INVALID\n");
					exit(1);
				}
				temp=pop(stk); //TO COLLECT ALL THE PARANTHESIS
			}

			else if(isalnum(infix[i]))
			{
				postfix[k]=infix[i];
//				printf("isalnum=%c\t%d\n",postfix[k],k);
				k++;
			}

			else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='%')
			{
				while( (top!=-1) && (priority(stk[top]) >= priority(infix[i])) && stk[top]!='(')
				{
					postfix[k]=pop(stk);
//					printf("Operators=%c\t%d\n",postfix[k],k);
					k++;
				}
				
				push(stk,infix[i]);
			}

			else
				{	
					printf("INVALID EXPRESSION!!\n");
				}
					
		}
	
	}
