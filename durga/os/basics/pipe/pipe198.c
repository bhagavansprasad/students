#include<stdio.h>
main()
{
	int p[2], pid, j;
	char* mas1 = " hello ,world";
//	char* mas2 = " hai, world";
	char inbuf[16];
	pipe(p);
	pid = fork();

	if(pid>0)
	{
	  close(p[0]);
		write( p[1], mas1, 16);
		sleep(1);
		read(p[0], inbuf, 16);
		printf("%s\n", inbuf);
	}
	else 
	{
	   close(p[1]);
		read(p[0], inbuf, 16);
		printf("%s\n",inbuf);
		sleep(1);
		write(p[1], mas1, 16);
		}
	
}

