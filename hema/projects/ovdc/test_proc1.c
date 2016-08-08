#include <stdio.h>
main()
{
	int i,pid,j;
printf("pid:%d\n\n",getpid());
	for(i=0 ; ;i++)
	{
			for(j=0;j<1000000000000000;j++)
			{
				//printf("parent process id:%d\n",getpid());

			}
//			sleep(2);
	}
}

