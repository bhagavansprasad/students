#include <stdio.h>
#include<string.h>
struct add
{
	char a [100];
	int b;
	int c;
};

struct reply
  {
  char buff[100];
  int first;
  int second;
  int res;
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
	int ret;
	struct add s;
	strcpy(s.a,"add");
		s.b=10;
		s.c=20;
		ret=write(wfd,&s,sizeof(s));
		printf("c.ret--->%d\n",ret);
		ret=read(rfd,&s,sizeof(s));
		printf("c.ret--->%d\n",ret);
		printf("c.answer--->%s\n",s.a);

}
int parent(int wfd,int rfd)
{
struct reply s1;
	int ret;
	ret=read(rfd,&s1,sizeof(s1));

	printf("%s \n",s1.buff);
	printf("first is %d\n",s1.first);
	printf("second is %d\n",s1.second);
	s1.res=s1.first+s1.second;
	printf("res-->%d\n",s1.res);

sprintf("sret--->%d\n",ret);
printf("s1.buff-->%s\n",s1.buff);

}
