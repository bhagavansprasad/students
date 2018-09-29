#include <stdio.h>
main()
{
	int n=255;
	showbits(n,8);
}
int showbits(int n,int size)
{
	int i,count=0;
	for(i=size-1;i>=0;i--)
	{
		if(n & (1<<i))
		{
			printf("1 ");
			count ++;
		}
		else
			printf("0 ");
	}
	printf("\n");
	printf("no of one's:%d\n",count);
}
