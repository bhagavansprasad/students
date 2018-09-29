#include<stdio.h>
#include<fcntl.h>
#define MSGSIZE 16
//char *msg2 = "bye";
main()
{
	char *msg[5] = {"hi","hello", "hw r u", "fine", "bye"};
	int p[2],pid;
	static int i=0;
	char inbuff[7];
	pipe(p);
	pid = fork();
	if(pid == 0)
	{
		for(;i < 5;)
		{
			printf("--->child<----\n");
			read(p[0],inbuff,10);
//			if(strcmp(inbuff, "bye")==0)
//			{
			printf("the child is = %s\n",inbuff);
			write(p[1],msg[i],10);
			i++;
			sleep(2);
//			}
		}
		//printf("the child is exiting");
	}
	else
	{
		for(;i<=5;)
		{

			printf("--->parent<---\n");
			i++;
			write(p[1],msg[i],10);
			//printf("the parent is = %s\n",msg[i]);
			sleep(2);
			read(p[0],inbuff,10);
			printf("the parent is =%s\n",inbuff);
		}
		printf("the parent is exiting");
	}
}
