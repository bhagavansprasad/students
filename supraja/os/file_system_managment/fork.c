#include <stdio.h>
int main()
{
	//fork();
	//printf("Hello world\n");

	//printf("This demonstrate the fork()\n");
	int pid = fork();
	//fork();
	//fork();
	//printf("Hello world\n");
	//sleep(1);
/*	printf("pid value : %d\n",pid);
	printf("pid value : %d\n",getpid());
	
	if(pid==0)
	{
		printf("child process\n");
		printf("pid value is : %d\n",getpid());
	}
	else
	{
		printf("parent process\n");
		printf("pid value is : %d\n",getpid());
	}
//	printf("The PID is %d\n",getpid());
*/
	if(pid<0)
	printf("fork failed\n");
	else
	printf("fork succeed\n");
}
