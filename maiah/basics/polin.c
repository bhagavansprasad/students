#include<stdio.h>
main()
{
	int a=926,c=0,b=a;
	c=(c*10)+(a%10);
	a=a/10;
	c=(c*10)+(a%10);
	a=a/10;
	c=(c*10)+(a%10);
	a=a/10;
	if(b==c)
	{
		printf("yes it is a polindrome");
	}
	else
	{
		printf("it is not a polindrome");
	}
}
