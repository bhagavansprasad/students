#include <stdio.h>

main()
{
	int pid ;
	int p[2];
	int retv = 0;
	char *buff = "hello";
	char inbuff[5];

	pipe(p);
	pid = fork();

	if( pid ==0 )
	{
		close(p[1]); //for pr203
		sleep(5);
		printf("child exiting \n");
	}
	else
	{
		close(p[1]); //for pr202 & pr204
		retv = read (p[0], inbuff , 5);
		printf("value returned :%d \n", retv);
	}
}
