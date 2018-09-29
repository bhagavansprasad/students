#include<stdio.h>
main()
{
	int a=20,m=1,i=1,c=0;
		while(a>0)
		{
			c=a&m;
			if(c==1)
			{
				printf("%d",i);
				exit(0);
			}
			a=a>>1;
			i++;
		}
	printf("no bit is 1");
}

