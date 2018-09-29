#include <stdio.h>
main()
{
	int a=1,b=-1,c,i;
	for(i=0;i<=5;i++)
	{
		c=a+b;
		b=a;
		c=a;
		printf("%d\n",c);
	}
}
