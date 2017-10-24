#include "stdio.h"
main()
{
	int i;

	for(i=1;i<=10;i++)
	{
		printf("%d\r\n",i);
		if (i>=0)
			break;

	}
	printf("%d\r\n",i);
}

