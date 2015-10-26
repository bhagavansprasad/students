#include <stdio.h>
main()
{
	int i,n=32,c=0,k;
	for(i=0;i<=7;i++)
	{
		k=n&(1<<i);
		if(k!=0)
		c++;
	}
	printf("c val is %d\n",c);
	if(c==1)
	printf("power of 2\n");
	else
	printf("not power of 2\n");
}
