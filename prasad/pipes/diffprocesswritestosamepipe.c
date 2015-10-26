#include"stdio.h"
#include"stdlib.h"
#define MSGSIZE 16
main()
{
    char *msg1="hello,i am child";
    char *msg2="hello,iam parent";
    char inbuf[MSGSIZE];
    int p[2],pid,j;
    pipe(p);
    pid=fork();
    if(pid>0)
        write(p[1],msg2,MSGSIZE);
  else 
    {
	write(p[1],msg1,MSGSIZE);
	for(j=0;j<=1;j++)
	{
	    read(p[0],inbuf,MSGSIZE);
	    printf("%s \n",inbuf);
	}
    }
    exit(0);
}
