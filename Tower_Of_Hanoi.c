//SOLVING TOWER OF HANOI WITH N DISKS

#include<stdio.h>
void toh(int n,char *s,char *d,char *a);

int main()
{
	int discs=0;
	printf("\nENTER THE NUMBER OF DISCS=");
	scanf("%d",&discs);
	
	toh(discs,"source","dest","aux");
	return 0;
}

void toh(int n, char * s ,char *d,char *a)
{
	if(n==1)
	{
		printf("\nMove disc %d from %s to %s",n,s,d);
	}
	else
	{
		toh(n-1,s,a,d);
		printf("\nMove disc %d from %s to %s ",n,s,d);
		toh(n-1,a,d,s);
	}
	printf("\n");
}

