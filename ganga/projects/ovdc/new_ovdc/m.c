#include <stdio.h>

main()
{
	int p[2];
	int retval = 0, wretval = 0;
	int pval = pipe(p);
	int pid = fork();
	
	if( pid == 0)
	{
		ovd(wretval);
	}
	
	else
	{
		ovc(retval);
	}
}	
