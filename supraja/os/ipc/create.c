#include<stdio.h>
#define MSGSIZE 16
int main()
{
	//char msg1[][10]={"hai","bye"};
	char *msg1={"hai"};
	char *msg2={"hellow"};
	//char msg2[][10]={"hello","bye"};
	char *msg3={"bye"};
	char *msg4={"bye"};
	char inbuff[MSGSIZE];
	int p[2],pid,i;
	pipe(p);
	pid=fork();
	if(pid>0)
	{
		printf("iam in parent\n");
		write(p[1],msg1,MSGSIZE);
		write(p[1],msg2,MSGSIZE);
		write(p[1],msg3,MSGSIZE);
		write(p[1],msg4,MSGSIZE);

	}
	else
	{
//		sleep(5);
		printf("iam in child\n");
		//sleep(5);
		for(i=0;i<=3;i++)
		{
			read(p[0],inbuff,MSGSIZE);
			printf("%s\n",inbuff);
//		sleep(5);
		}
	}
}	
