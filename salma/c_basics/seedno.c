#include<stdio.h>
main()
{   
    int b=123;
	int a,c;
	a=c=b;
	while(a!=0)
	{
		c=c*(a%10);
		a=a/10;
	}
	printf("%d is a seed no of %d \n ",c,b);
}
