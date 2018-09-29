#include <stdio.h>
main()
{
	int x = 257;
	int n = 0;
	int i,mask,res=0,a,b,c,m=20;
	mask = x;
	for(i=15;i>=0;i--)
	{
		c = mask&(1<<i);
		if(c==0)
			printf("0");
		else
			printf("1");
	}
	printf("\n");

	//for(i=8;i<(n+n);i++)
	//{
			mask=~(~0<<n)<<n;
			printf("mask -->%d ~mask-->%d\n",mask,~mask);
//	}
	
	for(i=15;i>=0;i--)
	{
		b = mask&(1<<i);
		if(b == 0)
			printf("0");
		else
			printf("1");
		//	res = x&mask;
	}
		
		printf("\n");
	//printf("res-->%d\n",res);
	
	printf("x&~mask-->%d\n",x&~mask);
	res = (x&~mask)|(m<<n);

	for(i=15;i>=0;i--)
	{
		a = res&(1<<i);
		if(a==0)
			printf("0");
		else
			printf("1");
	}
}
