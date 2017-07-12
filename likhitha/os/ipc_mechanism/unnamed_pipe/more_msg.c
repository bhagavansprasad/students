#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define SIZE 60

main()
{
	int fd,i=0,j=0;
	int pid;
	char *msg1[]={"hi", "how are you", "fine"," what else", "bye"};
	char *msg2[]={"hello", "fine what about you", "you"," have to say","bye", "hello"};
	char inbuff[SIZE];
	int p1[2];
	int p2[2];

	pipe(p1);
	pipe(p2);
	//fd = open("testfile2",O_RDWR);

	pid = fork();

	if(pid > 0)
	{
		close(p1[0]);
		close(p2[1]);
		for(i=0;i<5;i++)
		{
			write(p1[1],msg1[i],SIZE);
			//sleep(1);
		}
		for(i=0;i<5;i++)
		{
			read(p2[0],inbuff,SIZE);
			printf("from the parent---->%s\n",inbuff);
		}
	}
	else
	{
		close(p1[1]);
		close(p2[0]);
		for(i=0;i<4;i++)
		{
			read(p1[0],inbuff,SIZE);
			printf("from the child----->%s\n",inbuff);

			//	if(strcmp(inbuff,"bye")==0)
			//		exit(0);
			//
		}
		//write(fd,msg2[j],SIZE);
	}
	for(i=0;i<5;i++)
	{
	//	printf("%d\n",i);
		write(p2[1],msg2[i],SIZE);
	}
}
