#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define SIZE 60

main()
{
	int fd,i=0,j=0;
	int pid;
	char *msg1[5]={"hi", "how are you", "fine what else", "bye"};
	char *msg2[5]={"hello", "fine what about you", "you have to say","bye", "hello"};
	char inbuff[SIZE];
	fd = open("testfile2",O_RDWR);
	pid = fork();
	 if(pid == 0)
	 {
	 	while(1)
		{

			write(fd,msg1[i],SIZE);
			sleep(1);
			
			read(fd,inbuff,SIZE);
			printf("from the parent---->%s\n",inbuff);
			
			if(strcmp(inbuff,"bye")==0)
				exit(0);
			
			i++;
			sleep(2);
		}
	 }
	 else
	 {
	 	while(1)
		{
			read(fd,inbuff,SIZE);
			printf("from the child----->%s\n",inbuff);

			if(strcmp(inbuff,"bye")==0)
				exit(0);

			write(fd,msg2[j],SIZE);
			j++;
			sleep(2);
		}
	 }
}
