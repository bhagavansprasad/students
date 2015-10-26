#include <stdio.h>

main()
{
	int pid ,p[2],retv = 0;
	char *buff = "hello",inbuff[5];

	pipe(p);
	pid = fork();

	if( pid ==0 )
		printf("child exiting \n");

	else
	{
		retv = read (p[0], inbuff , 5);
		printf("value returned :%d \n", retv);
	}
}
