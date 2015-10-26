#include <stdio.h>
void main()
{
	printf("pid is %d\n",getpid());
	int pid;
	pid=fork();
	printf("pid  --->= %d\n",pid);
	printf("run the ps -el command%d\n",pid);
	printf("run the ps -el command%d\n",pid);
	sleep(50);
	printf("run the ps -el program once more%d\n",pid);
	printf("run the ps -el program once more%d\n",pid);
	for(; ;);
}
