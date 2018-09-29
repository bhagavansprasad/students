#include <stdio.h>

main()
{
	int i = 10, pid;
	pid = fork();
	if(pid == 0)
	{
		for( ;;)
		{
			printf("child:%d\n",i);
		}
	}
	else
	{
		for( ;;)
		{
			printf("parent :%d\n",i);
		}
	}

}
