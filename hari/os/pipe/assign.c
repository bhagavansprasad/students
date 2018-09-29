#include<stdio.h>
#define msgsize 16
main()
{
	char*msg1="hello,world";
	char*msg2="world,hello";
	char inbuf[msgsize];
	int retval;
	int p[2],pid;
	pipe(p);

	pid=fork();
	if(pid>0)
	{  
        printf("parent process\n");
	//	close (p[0]);
		retval=write(p[1],msg1,msgsize);
		printf("retval=%d\n",retval);
		sleep(1);
	//	close(p[1]);
		retval=read(p[0],inbuf,msgsize);
		printf("retval=%d\n",retval);
		printf("%s\n: ",inbuf);
	}
	if(pid==0)
	{
	    printf("child process\n");
	//	sleep(1);
	//	close(p[1]);
		retval=read(p[0],inbuf,msgsize);
		printf("retval=%d\n",retval);
		printf("%s\n: ",inbuf);
		retval=write(p[1],msg2,msgsize);
		printf("retval=%d\n",retval);
	//	sleep(2);
     }
}	 
    

