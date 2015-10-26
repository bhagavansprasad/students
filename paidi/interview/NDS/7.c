#include <stdio.h>
main()
{
	int i=1;
	while(i<=5)
	{
		printf("%d\r\n",i);
		if(i>2)
			goto here;
		i++;
	}
}

fun()
{
here:
	printf("pp");
}
