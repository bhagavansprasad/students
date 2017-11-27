#include <stdio.h>
int main()
{
	int pp[2],pc[2],j,pid;
	char msg1[20];
	char msg2[20];
	char msg3[20];

	pipe(pp);
	pipe(pc);

	pid=fork();

	if(pid==0)
	{
		close(pp[1]);
		close(pc[0]);
		write(pc[1],"hello daddy",12);
		read(pp[0],msg2,12);
		printf("child :%s\n",msg2);
		write(pc[1],"thank you papa",14);
	}

	else
	{
		close(pp[0]);
		close(pc[1]);
		read(pc[0],msg1,12);
		printf("parent :%s\n",msg1);
		write(pp[1],"hello baby",12);
		read(pc[0],msg3,14);
		printf("parent :%s\n",msg3);
	}

}
