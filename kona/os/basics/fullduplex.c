#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>
main()
{
	int p1[2],p2[2],a;
	char *msg1="hai";
	char *msg2="infosys";
	char buff[10];
	a=fork();
	pipe(p1);
	pipe(p2);
	if(a==0)
	{
		write(p1[1],msg1,10);
		sleep(1);
		read(p2[0],buff,10);
		printf("%s",buff);
	}
	else
	{
		read(p1[0],buff,10);
		printf("%s",buff);
		write(p2[1],msg2,10);
		//sleep(2);
	}
} 
