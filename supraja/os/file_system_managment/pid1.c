#include <stdio.h>
int main()
{
	int ppid;
	ppid = getppid();
	printf("parent process id :%d\n",ppid);
}
