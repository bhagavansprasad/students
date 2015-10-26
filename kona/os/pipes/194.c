#include <stdio.h>
main()
{
	int p[2],retval=0,i=0;
	while(1)
	{
		retval=pipe(p);
		if(retval==-1)
		{
			printf("max no of pipes that can be opened concurrently are%d\n",i);
			break;
		}
		i++;
		printf("%d %d\n",p[0],p[1]);
	}

}
