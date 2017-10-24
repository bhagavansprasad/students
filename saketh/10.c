#include "stdio.h"
main()
{
	int i;

	for(i=1;i<=10;i++)
	{
		printf("%d\r\n",i);
		if (i%5==0)
			i=i +4;

	}
	printf("%d\r\n",i);
}

