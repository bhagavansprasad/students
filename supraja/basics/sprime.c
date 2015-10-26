#include"stdio.h"
main()
{
	int n=5,i=2,s=0,p;
	while(i<n)
	{
		if(n%i==0)
		{
			printf("not prime\n");
			break;
		}
		i++;
	}
	if(i==n)
	{
		printf("%d\n",p);
	}
	s=s+p;
}

