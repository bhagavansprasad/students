#include<stdio.h>
main()
{
	int pid, i=10, ppid ;
	pid = getpid();
	ppid = getppid();
	printf("process id is %d\n",pid);
	printf(" parent process id is %d\n",ppid);
//	for( i = 0; i<=4000; i++)
//	printf("%d  ",i);
	//sleep(15);
	return 0;
}
