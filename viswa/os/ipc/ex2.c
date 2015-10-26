#include <stdio.h>

main()
{

	int retv , p[2] ,pid;
	char buff[100] = "hello this is viswanath yadav";
	pipe(p);
	pid = fork();
	if(pid == 0)
	{
		write(p[1] , buff , 20);
	}
	else
	{
		close(p[1]);
		retv  = read(p[0] , buff , 20);
		printf("retv = %d \n", retv);
		retv  = read(p[0] , buff , 20);
		printf("retv = %d \n", retv);
	}
}
