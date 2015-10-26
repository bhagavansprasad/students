#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define SIZE 60

main()
{
	int fd,fd1,i=0,j=0;
	int pid;
	char *msg1[]={"hi", "how are you", "fine what else", "bye"};
	char *msg2[]={"hello", "fine what about you", "you have to say","bye", "hello"};
	char inbuff[SIZE];
	fd = open("testfile2",O_RDWR);
	fd1=open("testfile3",O_RDWR);

	pid = fork();
	if(pid == 0)
	{

		for(i=0;i<4;i++)
		{
			write(fd,msg1[i],SIZE);
			//sleep(1);
			//i++;
		}
		//	sleep(1);
		for(i=0;i<4;i++)
		{
			read(fd1,inbuff,SIZE);
			printf("from the child---->%s\n",inbuff);

			if(strcmp(inbuff,"bye")==0)
				exit(0);




		}

	}
	else
	{
		for(i=0;i<4;i++)
		{
			read(fd,inbuff,SIZE);
			printf("from the parent----->%s\n",inbuff);

			//	if(strcmp(inbuff,"bye")==0)
			//		exit(0);

			//write(fd,msg2[j],SIZE);
			//	i++;
		}
		for(i=0;i<4;i++)
		{
			write(fd1,msg2[i],SIZE);
			//	j++;
		}
		//	sleep(2);
	}
}
