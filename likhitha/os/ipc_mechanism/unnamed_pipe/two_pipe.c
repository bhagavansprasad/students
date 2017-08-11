#include <stdio.h>

int main()
{
	int p1[2] , p2[2] , pid;
	char msg1[20];
	char msg2[20];
	char msg3[20];

	pipe(p1);
	pipe(p2);

	pid=fork();

	if(pid==0)
	{
		close(p1[1]);    //close pipe1 write
		close(p2[0]);    //close pipe2 read
		write(p2[1],"hello daddy",12);   //write to pipe2

		read(p1[0],msg2,12);  
		printf("child :%s\n",msg2);
		write(p2[1],"thank you papa\n",14);
	}

	else
	{
		close(p1[0]);        //close pipe1 read
		close(p2[1]);        //close pipe2 write
		read(p2[0],msg1,12);       //read in pipe2
		printf("parent :%s\n",msg1);

		write(p1[1],"hello baby",12);
		read(p2[0],msg3,14);
		printf("parent :%s\n",msg3);
	}

}
