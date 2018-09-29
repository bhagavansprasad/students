#include <stdio.h>
#include <signal.h>
sleep(i)
int i;
{
	alarm(i);
	pause();
}
