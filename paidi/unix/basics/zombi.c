#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() 
{
//* RUN with a.out & - and check ps -el to see process table *//
	if (fork() > 0) 
	{
		printf("e process...");
		/* this is a child: dies immediately and becomes zombie */
		sleep(50);
	}

	printf("Please, press enter after looking at the zombie process...");
}
