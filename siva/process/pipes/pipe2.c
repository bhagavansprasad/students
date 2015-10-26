#include<stdio.h>
#include<unistd.h>
main()
{
	int pid,p[2],val;
	char *msg="AuRA NETWORKS";
	char inbuff[25];
	pipe(p);
	pid=fork();
	if(pid>0)
	{
		write(p[1],msg,10);
		close(p[0]);
		printf("PARENT PROCESS DESCRIPTORS p[0]= %d p[1]= %d\n",p[0],p[1]);
		read(p[0],inbuff,10);
		printf("%s\n",inbuff);
	}
	else
	{
		close(p[1]);
		val=	write(p[1],msg,10);
		if(val==10)
		{
			printf("writing success\n");
		}
		else
		{
			printf("writng failed\n");
		}
		printf("CHILD PROCESS DESCRIPTORS p[0]= %d p[1]= %d\n",p[0],p[1]);
		read(p[0],inbuff,10);
		printf("%s\n",inbuff);
	}
}
