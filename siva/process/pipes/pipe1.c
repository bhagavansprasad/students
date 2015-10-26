#include<stdio.h>
#include<unistd.h>
main()
{
	int pid,p[2];
	pipe(p);
	pid=fork();
	if(pid>0)
	{
		printf("PARENT PROCESS DESCRIPTORS p[0]= %d p[1]= %d\n",p[0],p[1]);
	}
	else
		printf("PARENT PROCESS DESCRIPTORS p[0]= %d p[1]= %d\n",p[0],p[1]);
}
