#include <stdio.h>
main()
{
	int i;
	for(i=1;i<=10; )
	{
		printf("%d\n",i);
		if(i<=7)
			i+=2;
	}
	printf("i:%d",i);
}
