#include<stdio.h>
main()
{
	int p[2],retval,i=0;
	while(1)
	{
		retval=pipe(p);
		printf("retvalue is %d\n",retval);
		if(retval==-1)
		{
			printf("max no of pipes is that can be open concurrently are %d\n",i);
			break;
		}
		i++;
		printf("%d %d \n",p[0],p[1]);
	}
}
