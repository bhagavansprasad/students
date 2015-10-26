#include"stdio.h"

main(int argc, char *argv[])
{
    int a[2], pid = 0, pid_count, i;

    pipe(a);
    pid = fork();

    if(pid == 0)
    {
	close(a[0]);

	for(; ;)
	    ovd(a[1], argc, argv);
    }	
    else
    {	
	close(a[1]);
	ovc(a[0]);
    }
}
