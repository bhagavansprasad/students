#include <stdio.h>
main()
{
	int p[2], pid, rval;
	char name[5][20] = {"hi", "bye", "how are you", "i am fine", "hello"};
	char buff[100];
	pipe(p);
	pid = fork();
	if(pid == 0)
	{
		while(1)
		{
			rval = read(p[0], buff, 20);
			buff[rval] = '\0';
			printf("%s\n", buff);
			if(!strcmp(buff,"bye"))
				break;
		}
	}
	else
	{
		write(p[1], name[0], 20);
		sleep(1);
		write(p[1], name[1], 20);
		sleep(1);
		write(p[1], name[2], 20);
		sleep(1);
		write(p[1], name[3], 20);
		sleep(1);
		write(p[1], name[4], 20);
		sleep(1);
	}
}
