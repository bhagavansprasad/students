#include<stdio.h>
#include<unistd.h>
main()
{
	int p1[2],p2[2],pid,w1,r1,w2,r2,len=10,i,j;
	char *msg1="hello world hi world";
	char buff[100];
	char inbuff[100];
	char *msg2="full duplex operation";
    pipe(p1);
	pipe(p2);
	pid=fork();
	if(pid>0)
	{
	  for(i=0;i<=5;i++)
	  {
		w1=write(p1[1],msg1,len);
		printf("write w1 is %d\n",w1);
		printf("write w1 is %s\n",msg1);
		close(p1[0]);
		r2=read(p2[0],inbuff,len);
		printf("read  r2 is %d\n",r2);
		printf("read r2 is %s\n",inbuff);
		close(p2[1]);
	  }

	}

	else
	{ 
	  for(j=0;j<=5;j++)
	  {
		r1=read(p1[0],buff,len);
		printf("read r1 is %d\n",r1);
		printf("read is r1 %s\n",buff);
		close(p1[1]);

		w2=write(p2[1],msg2,len);
		printf("write is w2 %d\n",w2);
		printf("write is w2 %s\n",msg2);
		close(p2[0]);

		}

	}

}
