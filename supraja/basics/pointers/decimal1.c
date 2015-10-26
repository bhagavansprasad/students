#include<stdio.h>
int main()
{
	int a=300;
	int i;
	char *p=(char *)&a;
	for(i=3;i>=0;i--)
	{
		printf("\n%02d ",*(p+i));
		printf("%u",&*(p+i));
	}
}	
