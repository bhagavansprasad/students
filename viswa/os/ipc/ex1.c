/* tyo find the size of the pipe */

#include <stdio.h>


main()
{
	int retv = 0,i = 0 ,p[2];
	char buff[100] =" hi this viswanath yadav amruthala";
	pipe(p);

	while(1)
	{
		retv = write(p[1],buff,1);
		printf("i value :->%dretv:->%d\n",i,retv);
		if(retv != 1)
		{
		//printf("pipe size:->%d", i*20);
		break ;
		}
		i++;
	}
}
