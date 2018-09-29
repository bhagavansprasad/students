#include <stdio.h>
main()
{
	int ppid;
	ppid=getppid();
	printf("parent process ID is %d\n",ppid);
}
