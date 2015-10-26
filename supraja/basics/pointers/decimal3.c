#include<stdio.h>
int main()
{
	int i;
	short int a=300;
	char *p=(char *)&a;
	for(i=0;i<=1;i++)
	{
		printf("%d\n",*(p+i));
	}
}
