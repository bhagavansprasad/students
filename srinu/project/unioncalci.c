#include <stdio.h>
#include <string.h>
struct add
{
	int a,b,c,d,e;
};
struct div
{
	int a,b;
};
struct sub
{
	int a,b;
};
struct mul
{
	int a,b,c,d,e;
};
struct mod
{
	int a,b;
};
union data
{
	struct add a;
};
struct cmd
{
	int cmd;
	union data u;
};
main()
{
	int pid;
	int p1[2];
	int p2[2];
	pipe(p1);
	pipe(p2);
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
int child(int wfd,int rfd)
{
	int ret=0;
	union data u;
	u.a.a=10;
	u.a.b=20;
	u.a.c=30;
	u.a.d=40;
	u.a.e=50;
	ret=write(wfd,&u,sizeof(u));
	printf("c:-->write return value:%d\n",ret);
	printf("c:-->%d%d%d%d%d\n",u.a.a,u.a.b,u.a.c,u.a.d,u.a.e);
}
int parent(int wfd,int rfd)
{
	union data u;
	char str[100]="add 10 20 30 40 50";
	char cmd[10];
	int ret,sum=0;
	ret=read(rfd,&u,sizeof(u));
			printf("s:-->read ret value:%d\n",ret);
			printf("s:-->%d%d%d%d%d\n",u.a.a,u.a.b,u.a.c,u.a.d,u.a.e);
			sscanf("s:-->%s%d%d%d%d%d\n",cmd,u.a.a,u.a.b,u.a.c,u.a.d,u.a.e);
			printf("s1:-->%d%d%d%d%d\n",u.a.a,u.a.b,u.a.c,u.a.d,u.a.e);
			sum=u.a.a+u.a.b+u.a.c+u.a.d+u.a.e;
			printf("s:-->sum:%d\n",sum);
			ret=write(wfd,&u,sizeof(sum));
			printf("s->ret:%d\n",ret);
}
