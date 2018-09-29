#include <stdio.h>

main()
{
	int p[2],pid;
	char *msg1 = "hello";
	char *msg2 = "hi";
	char *msg3 = "what";
	char *msg4 = "when";
	char *msg5 = "where";
	char *msg6 = "why";
	char inbuff[20];
	pipe(p);
	pid = fork();

	if(pid == 0)
	{
		write(p[1],msg3,20);
		write(p[1],msg4,20);
		sleep(1);
		
		read(p[0],inbuff,20);
		printf("from the parent is %s\n",inbuff);
		
		read(p[0],inbuff,20);
		printf("from the parent is %s\n",inbuff);
		
		write(p[1],msg5,20);
		write(p[1],msg6,20);
		sleep(2);
	
	}
	
	else
	
	{
		read(p[0],inbuff,20);
		printf("from the child is %s\n",inbuff);
		
		read(p[0],inbuff,20);
		printf("from the child is %s\n",inbuff);

		write(p[1],msg1,20);
		write(p[1],msg2,20);
		sleep(2);

		read(p[0],inbuff,20);
		printf("from the child is %s\n",inbuff);
		read(p[0],inbuff,20);
		printf("from the child is %s\n",inbuff);
		sleep(2);
	}
}
