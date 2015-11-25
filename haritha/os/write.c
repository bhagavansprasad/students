#include <stdio.h>
int p[2];
<<<<<<< HEAD
main()
{
	
	int pid;
=======
//#define MAX 5
main()
{
	
	int pid=0;
>>>>>>> cf910f9351b12602d46981bd3b7c9eb08fcb4592
	pipe(p);
	pid=fork();
	if(pid==0)
	{
<<<<<<< HEAD
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
=======
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
>>>>>>> cf910f9351b12602d46981bd3b7c9eb08fcb4592
}

