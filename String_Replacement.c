#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// FUNTIONS REQUIRED
// LENGTH, FINAL STRING , FIND STRING
//

int length(char *string);
int find_string(char *str,char *rep,char *pat,int str_len,int pat_len,int rep_len);
int fact(int n);

int fact(int n)
{
	if(n==1)
		return 1;
	else
		return ( (n*(n+1) ) / 2 );
}


int main()
{
	char str[50],rep[50],pat[50];
	int str_len,pat_len,rep_len;
	printf("\nEnter the string which you want to enter\n>");
	scanf("%s",str);
	printf("Enter the pattern string\n");
	scanf("%s",pat);
	printf("Enter the string which needs to be replace\n");
	scanf("%s",rep);
	
	str_len=length(str);
	pat_len=length(pat);
	rep_len=length(rep);
	printf("Length of the main string=%d\n",str_len);
	printf("Length of the pattern string=%d\n",pat_len);
	printf("Length of the replace string=%d\n",rep_len);

	find_string(str,rep,pat,str_len,pat_len,rep_len);
	return 0;



}


int length(char *string)
{
	int i,count=0;
	for(i=0;string[i]!='\0';i++)
	{
		++count;
	}
	return count;
}

int find_string(char *str,char *rep,char *pat,int str_len,int pat_len,int rep_len)
{
	int i;
	int j;
	int k;
	int flag=0;
	int l=0;
	printf("STRING\t\tPATTERN\n");
	for(k=0;k<=(str_len-pat_len);k++)
	{

		for(i=k,j=0;str[i]!='\0',pat[j]!='\0';i++,j++)
		{
			printf("%c\t\t%c\n",str[i],pat[j]);
			if(str[i]==pat[j])	
			{		
			for(l=0;l<pat_len;l++)
			{	

				if(str[i+l]==pat[j+l])
				{	
					printf("\n......%c.......%c\n",str[i+l],pat[j+l]);
					++flag;



				}
			}
			}
			
		}
		printf("\n");
	//	j=0;
	}
	printf("\nFLAG=%d\n",flag);
	if(flag==fact(pat_len))
		printf("\n\tPATTERN STRING FOUND!!\t\n");
	else
		printf("\n\tPATTERN NOT FOUND !!\t\n");
	return flag;
}


