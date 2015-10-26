#include <stdio.h>
main()
{
	int pid=fork();
	if(pid>0)
	{
		printf("parent\n");
		sleep(50);
	}
}
