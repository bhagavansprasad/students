#include <stdio.h>
int p[2];
//#define MAX 5
main()
{
	
	int pid=0;
	pipe(p);
	pid=fork();
	if(pid==0)
	{
		//printf("child\n");
		child();
	}
	else
	{
	
		//printf("parent\n");
		parent();
	}
}
child()
{
	
	char b[10]="hello";
	printf("I am in child to write data");
		write(p[1],b,5);
}
parent()
{

	char buff[10];
	printf("I am in parent to read data");
		read(p[0],buff,5);
		printf("%s\n",buff);
}

