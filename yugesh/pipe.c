#include <stdio.h>
main()
{
	int pp[2],pc[2],pid;
	char msg1[20];
	char msg2[20];
	char msg3[20];
	char msg4[20];
//	pid=fork();
	pipe(pp);
	pipe(pc);
	pid=fork();
	if(pid==0)
	{
		close(pp[0]);
		close(pc[1]);
		write(pp[1],"hello dady",12);
		read(pc[0],msg2,12);
		printf("%s\n",msg2);
		write(pp[1],"bye dady",14);
		read(pc[0],msg4,14);
		printf("%s\n",msg4);

	}
	else
	{
		close(pp[1]);
		close(pc[0]);
		read(pp[0],msg1,12);
		printf("%s\n",msg1);
		write(pc[1],"hello son",12);
		read(pp[0],msg3,14);
		printf("%s\n",msg3);
		write(pc[1],"see you soon",18);
	}
}
