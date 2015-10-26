#include "stdio.h"
main()
{
	int a=0,b=1,n=5,i;
	{
		for(i=3;i<n;i+2)
		{
			a=a+b;
			b=a+b;
		}
		printf("%d"a,b);
	}
}
