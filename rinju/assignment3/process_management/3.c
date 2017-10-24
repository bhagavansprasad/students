#include <stdio.h>
main()
{
	int pid;

	printf( " I am forking a child process \n ");
	pid  =	fork ();
	if(pid==0)
	{
		printf("i am a chilld process\n");
		printf("my id is:%d \n",getpid());
		printf("my parent id is:%d \n",getppid());
		printf("my user id is:%d \n",getuid());
		printf("my effective user id is:%d \n",geteuid());
		printf("my group id is:%d \n",getgid());
		printf("my effective group id is:%d \n",getegid());
	}
	else
	{
		printf("i am a parent process\n");
		printf("my id is:%d \n",getpid());
		printf("my parent id is:%d \n",getppid());
		printf("my user id is:%d \n",getuid());
		printf("my effective user id is:%d \n",geteuid());
		printf("my group id is:%d \n",getgid());
		printf("my effective group id is:%d \n",getegid());
	}



  //  fork ();
	//fork ();
	//printf( "who am i ? child or parent ? My ID process : %u \n ", getpid());
   }

