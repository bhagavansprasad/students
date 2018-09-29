#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigkey();
main()
{
	
	signal(SIGHUP , SIG_IGN);
	for(;;);
}
