#include "stdio.h"
main()
{
	int i=0;
	int n = 10;
	
	for(;i<n;i=i+2)
	{
		printf("%d\r\n",i);
	}
	printf("%d\r\n",i);
}
