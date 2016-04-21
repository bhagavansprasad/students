#include<stdio.h>
void main()
{
	int a=426,c;
	c=a%10;a=a/10;
	c=c+a%10;a=a/10;
	c=c+a%10;a=a/10;
	printf("%d",c);
}

