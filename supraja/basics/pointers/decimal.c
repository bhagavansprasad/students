#include<stdio.h>
int main()
{
	int a=300;
	int i;
	char *b;
	b=(char *)&a;
	for(i=0,b=&a;i<4;i++,b++)
	{
		printf("\n %d --> ",*b);
		printf(" %u ",&*b);
	}
}
