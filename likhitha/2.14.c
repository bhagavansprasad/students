#include <stdio.h>
main()
{
	int i,j;
	for(i=1;i<=5;i++)
	{
		printf("%d\n",i);
		for(j=0;j<=5;j++)
		{
			printf("%d\n",j);
			if(j%2)
				i+=2;
		}
	}
	printf("i:%d,j:%d\r\n",i,j);
}
