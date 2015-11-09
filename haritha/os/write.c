#include <stdio.h>
int p[2];
main()
{
	
	int pid;
	pipe(p);
	pid=fork();
	if(pid==0)
	{
		child();
	}
	else
		parent();
}
child()
{
//	int i;
//	for(i=0;i<4 ;i++)
	{
		write(p[1],"hello",5);
	}
}
parent()
{
//	int i;
	char buffer[10];
//	for(i=0;i<4 ;i++)
	{
		read(p[0],buffer,5);
		printf("%s",buffer);
	}
}

