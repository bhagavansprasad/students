#include <stdio.h>
main()
{
	int p[2],retval,i=0;
	while(1)
	{
		retval = pipe(p);
		if(retval == -1)
		{
			printf("max pipes : %d\n",i);
			break;
		}
		i++;
		printf("%d\t%d\n",p[0],p[1]);
	}
}
