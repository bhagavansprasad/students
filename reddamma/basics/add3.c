#include<stdio.h>
main()
{
	int a=626,c=0,b;
	b=a;
	c=(c*10)+(a%10);
	a=a/10;
	c=(c*10)+(a%10);
	a=a/10;
	c=(c*10)+(a%10);
	a=a/10;
	if(b==c)
	{
		printf("yes,because reverse of 626 is also 626");
	}

}
