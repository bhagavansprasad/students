#include<stdio.h>
#include<fcntl.h>
main()
{
	int p[2],retval,i = 0;
	while(1)
	{
		retval = pipe(p);
		if(retval == -1)
		{
			printf("Max no of pipes that can be opend concurrently are %d\n",i);
			break;
		}
		i++;
		printf("%d  %d\n",p[0],p[1]);
	}
}
