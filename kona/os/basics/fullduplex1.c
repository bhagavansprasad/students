#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>
main()
{
	int pp[2],pc[2],pid;
	char msg1[20];
	char msg2[20];
	char msg3[20];
	pipe(pp);
	pipe(pc);
	pid=fork();
	if(pid==0)
	{
		close(pp[1]);
		close(pc[0]);
		write(pc[1],"hello sreenu",14);
		read(pp[0],msg2,12);
		printf("%s\n",msg2);
		write(pc[1],"thank you",10);
	}
	else
	{
		close(pp[0]);
		close(pc[1]);
		read(pc[0],msg1,14);
		printf("%s\n",msg1);
		write(pp[1],"hello dude",12);
		read(pc[0],msg3,10);
		printf("%s\n",msg3);
	}
}

