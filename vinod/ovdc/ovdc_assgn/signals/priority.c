#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
main()
{
	int which = PRIO_PROCESS;
	id_t pid;
	int ret;
	int priority = -18;
	pid = getpid();
	ret = getpriority(which,pid);
	printf("get priority of process -> %d\n", ret);
	ret = setpriority(which,pid,priority);
	if(ret < 0)
	{
		perror("Unable to set -> ");
		exit(1);
	}
	printf("set priority of process -> %d\n", ret);
}
