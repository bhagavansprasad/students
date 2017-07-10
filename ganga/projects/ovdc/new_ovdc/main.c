#include <stdio.h>
#include "defs.h"

int get_pids_from_args(int *pids, int argc, char *argv[])
{
	int i = 0;

	for(i = 1; i < argc; i++)
		pids[i-1] = atoi(argv[i]);

	return argc - 1;
}

int main(int argc, char *argv[])
{
	printf("%u\n" , getpid());
	int pipe_descriptors[2];
	int i, pid, retval, ovdc, ovcd ;
	int giffs = 0, proc_count ;
	int pids[100];

	proc_count = get_pids_from_args(pids, argc, argv);

	for (i = 0; i < proc_count; i++)
	{
		printf("-->%d. %d\n", i+1, pids[i]);
	}

	retval = pipe(pipe_descriptors);
	pid = fork();

	if(pid == 0)
	{
		close(pipe_descriptors[0]);
		ovdc = ovd(pipe_descriptors[1], pids, proc_count);
	}
	else
	{
		close(pipe_descriptors[1]);
		ovcd = ovc(pipe_descriptors[0]);
	}
}

