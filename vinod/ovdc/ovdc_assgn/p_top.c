#include <stdio.h>
main()
{
	int i=0;
	printf("pid : %d\r\n", getpid());
	sleep(10);
	while(1)
		printf("1");
}
