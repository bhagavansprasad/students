#include <stdio.h>

int main()
{
	int pid, p[2],rd;
	char buff[50];

	char msg1[20] = "aaaaaaaaaaaaaaaaaaaa";
	char msg2[20] = "bbbbbbbbbb";
	char msg3[20] = "cccccccccccccccccccc";
	char msg4[10] = "dddddddddd";

	pipe(p);
	pid = fork();

	if(pid != 0)
	{
		write(p[1], msg1, 20);
		sleep(1);
		rd = read(p[0], buff, 10);
		rd[buff] = '\0';
		printf(" parent process is recieving from the child process %s\n", buff);

		write(p[1], msg3, 20);
		sleep(1);
		rd = read(p[0], buff, 10);
		rd[buff] = '\0';
		printf(" parent process is recieving from the child process %s\n", buff);
	}

	else
	{
		rd = read(p[0], buff, 20);
		rd[buff] = '\0';
		printf(" child process is recieving from the parent process %s\n", buff);
		write(p[1], msg2, 10);
		sleep(1);

		rd = read(p[0], buff, 20);
		rd[buff] = '\0';
		printf(" child process is recieving from the parent process %s\n", buff);
		write(p[1], msg4, 10);
		sleep(1);
	}
}
