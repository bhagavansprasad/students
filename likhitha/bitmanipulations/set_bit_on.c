#include <stdio.h>
main()
{
	int n=10 , pos=3 , i = 0, temp[4] = { };
	//n|=1<<(pos-1);

	//printf("%d\n",n);
	while( n > 0)
	{
		n=n>>i;
		temp[i]=n&1;
		i++;
	}
	for(pos = 7; pos >= 0; pos--)
	{
		printf("%d",temp[pos]);
	}
	printf("\n");
}
