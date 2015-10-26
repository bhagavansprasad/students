#include<stdio.h>
#include<unistd.h>
main()
{
	int pid,p[2],len=10,r1,w1,r2,w2,i,j;
	char *msg1="hello world";
	char *msg2="unix operating system";
	char inbuff[100],buff[100];
	pipe(p);
	pid=fork();
	if(pid>0)
	{
		for(i=0;i<=5;i++)
		{
			w1=write(p[1],msg1,len);
			printf("w1 is %s\n",msg1);
			r2=read(p[0],inbuff,len);
			printf("r2 is %s",inbuff);
		}	

	}

	else
	{
		for(j=0;j<=5;j++)
		{
			r1=read(p[0],buff,len);
			printf("r1 is %s\n",buff);
			w2=write(p[1],msg2,len);
			printf("w2 is %s\n",msg2);
		}	


	}
}
