#include "defs.h"

int main()
{  
	int fdr=0;
	int fdw=0;
	int pipe_fds[2];

	if(pipe(pipe_fds) < 0)
	{
		perror("Error in creating a pipe :");
		exit(1);
	}

	fdr = pipe_fds[0];
	fdw = pipe_fds[1];

	
	if(fork() > 0)
	{
		while(1)
		{
			ovd(fdw);
			sleep(1);
		}
	}
	
	else
	{
		while(1)
		{
			ovc(fdr);
			sleep(1);
		}
	}
	return 0;
}
