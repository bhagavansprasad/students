
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSGSIZE 64

int chld_process(int wfd, int rfd)
{
	char *msg1[5]={"hi papa","how are u","where are u","hai","bye"};
	char inbuf[MSGSIZE];
	int i = 0;
	int retval = 0;

	for(i = 0; i < 5; i++)
	{
		printf("-->C Going for Write...\n");
		retval = write(wfd, msg1[i], strlen(msg1[i]));
		printf("-->C Write retval :%d\n", retval);

		printf("-->C Going for read...\n");
		retval = read(rfd, inbuf, MSGSIZE);
		inbuf[retval]='\0';
		printf("-->C Read retval :%d, msg :%s\n", retval, inbuf);
		
		if(strcmp(inbuf, "bye") == 0)
		{
			printf("C: parent sent 'bye' exiting...\n");
			exit(0);
		}
		sleep(2);
	}
	return 0;
}

int parent_process(int wfd, int rfd)
{
	char *msg2[5]={"hello baby", "fine", "bangalore","hello","hey"};
	char inbuf[MSGSIZE];
	int i = 0;
	int retval = 0;

	for(i=0; i<5; i++)
	{
		printf("---->P Going for read...\n");
		retval = read(rfd, inbuf, MSGSIZE);
		inbuf[retval]='\0';
		printf("---->P Read retval :%d, msg :%s\n", retval, inbuf);
		
		if(strcmp(inbuf, "bye") == 0)
		{
			printf("P: child sent 'bye' exiting...\n");
			exit(0);
		}
		
		printf("---->P Going for Write...\n");
		retval = write(wfd, msg2[i], strlen(msg2[i]));
		printf("---->P Write retval :%d\n", retval);

		sleep(2);
	}
	return 0;
}

main()
{
	int pp[2],pc[2],read_retval=0,pid;

	pipe(pp);
	pipe(pc);

	pid=fork();

	if(pid == 0)
		chld_process(pp[1], pc[0]);
	else
		parent_process(pc[1], pp[0]);

	exit(0);
}
