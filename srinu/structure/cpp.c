#include<stdio.h>
#include <string.h>
main()
{
	int pid=0;
	int p1[2];
	int p2[2];
	pipe(1);
	pipe(2);
	pid=fork();
	if(pid==0)
	{
		child(p1[1],p2[0]);
	}
	else
	{
		parent(p2[1],p1[0]);
	}
}
void child(int wfd,int rfd)
{
	char creq[100]="add 100 200";
	char creply[100];
	int retval=0;
	retval=write(wfd,creq,strlen(creq));
	printf("-->C.write retval:%d\n",retval);
	sleep(2);
	retval=read(rfd,creply,100);
	printf("-->read retval:%d\n",retval);
	creply[retval]='\0';
	printf("C.answer:%s\n",creply);
}
void parent(int wfd,int rfd)
{
	int sum,first=0,second=0;
	char sreq[100];
	char sreply[100];
	char cmd[10];
	int retval=0;
	sleep(1);
	retval=read(rfd,sreq,100);
	printf("-->s.read retval:%d\n",retval);
	sreq[retval]='\0';
	printf("-->.read retval:%s\n",sreq);
	sscanf(sreq,"%s %d %d",cmd,&first,&second);
	printf("-->s.cmd:%s\n",cmd);
	printf("-->s.first:%d\n",first);
	printf("-->s.second:%d\n",second);
	sum=first+second;
	printf("-->s.num:%d\n",sum);
	retval=write(wfd,sreply,strlen(sreply));
	printf("-->s.write retval:%d\n",retval);
}
