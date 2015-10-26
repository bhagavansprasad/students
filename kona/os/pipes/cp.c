#include <stdio.h>
main()
{
	int p[2],pid;
	char *msg1="hi how are you,my name is sreenivasulareddy,now present i am in aura institute";
	char inbuf[100];
	pipe(p);
	pid=fork();
	if(pid==0)
	{
		write(p[1],msg1,10);
		sleep(2);
		read(p[0],inbuf,30);
		printf("--->child buf is :%s\n",inbuf);
	}
	else
	{
		read(p[0],inbuf,10);
		printf("------>aprent buf is :%s\n",inbuf);
		write(p[1],msg1,30);
		sleep(2);
	}
}
