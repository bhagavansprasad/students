#include <stdio.h>
#include <stdlib.h>
#define MSGSIZE 16
main()
{
	char *msg1="hello,world";
	char inbuf[MSGSIZE];
	int p[2],pid;
	pipe(p);
//	pid=fork();
	if(pid>0)
		write(p[1],msg1,MSGSIZE);
	else
	{
		read(p[0],inbuf,MSGSIZE);
		printf("%s\n",inbuf);
		sleep(1);
	}
	exit(0);
}
//	printf("in child p[0] is %d p[1] is %d\n",p[0],p[1]);
//else
//	printf("in parent p[0] is %dp[1] is %d\n",p[0],p[1]);
//}
