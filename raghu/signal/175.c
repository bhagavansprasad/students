#include <stdio.h>

void sigkey();

main()
{
	printf("press CTRL\\ key \n");
	signal(SIGQUIT,sigkey);
	for(;;);
}

void sigkey()
{
	printf("recevied signal\n");
}
