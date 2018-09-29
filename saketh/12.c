#include "stdio.h"
main()
{
	int i;

	for(i=1;i<=10;)
	{
		printf("%d",i);
		if (i>=5)
			i+=2;;

	}
	printf("%d\r\n",i);
}

