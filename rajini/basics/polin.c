#include<stdio.h>
main()
{
	int a=626,b=626,c=0;
	b=a;
	c=(c*10)+(a%10);
	a=a/10;
	c=(c*10)+(a%10);
	a=a/10;
	c=(c*10)+(a%10);
	if(b==c)
	{
		printf(" is a polindrom\n");
	}
	else
	{
		printf("not polindrom\n");
	}
}
