#include<stdio.h>
int main()
{
	int i,n=4;
	int a=300;
	char *p=&a;
	for(i=0;i<n;i++)
	{
		printf("%d\n",*p);
		p++;
	}
}
