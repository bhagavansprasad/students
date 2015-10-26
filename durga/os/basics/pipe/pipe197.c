#include<stdio.h>
main()
{
	int p[2], pid;
	char* mas1 = " hello ,world";
	char* mas2 = " hai, world";
	char inbuf[16];
	pipe(p);
	pid = fork();
//	pipe(p);

	if(pid>0)
	{
		write( p[1], mas1, 16);
		sleep(2);
		read( p[0], inbuf, 16);
		printf("%s\n",inbuf);
	}
	else 
	{
		read( p[0], inbuf, 16);
			printf("%s\n",inbuf);
		write(p[1], mas2, 16);
		sleep(3);
	}
}

