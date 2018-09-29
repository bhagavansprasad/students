#include<stdio.h>
#include <stdlib.h>
main()
{
	int a=2,n,m=0xaaa,c;
	a=a>>1;
	while(a>=1)
		{
			n=a&1;
			if(n==1)
				a=a>>2;
			else
			{
			printf("0");
			exit(0);
			}

		}
	printf("1");
	//c=a&m;
	//printf("%d",c);
	//if(c==m)
	//printf("1");
	//else
	//printf("0");
}


