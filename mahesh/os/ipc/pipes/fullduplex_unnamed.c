#include <stdio.h>
main()
{
	int pp[2],pc[2],j,pid;
	char m1[20];
	char m2[20];
	char m3[20];
	pipe(pp);
	pipe(pc);
	pid = fork();
	if(pid == 0)
	{
		close(pp[1]);
		close(pc[0]);
		write(pc[1],"hello daddy",12);
		read(pp[0],m2,12);
		printf("%s\n",m2);
		write(pc[1],"thank you papa",14);
	}
	else
	{
		close(pp[0]);
		close(pc[1]);
		read(pc[0],m1,12);
		printf("%s\n",m1);
		write(pp[1],"hello baby",12);
		read(pc[0],m3,14);
		printf("%s\n",m3);
	}
}
