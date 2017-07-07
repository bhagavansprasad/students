#include <stdio.h>

int get_pids_from_args(int *pids, int argc, char *argv[])
{
	int i = 0;

	for(i = 1; i < argc; i++)
		pids[i-1] = atoi(argv[i]);

	return argc-1;
}

int main(int argc, char *argv[])
{
	int pipe_descriptors[2];
	int pid, retval ,i;
	int giffs=0, proc_count ;
	int pids[100];

	proc_count = get_pids_from_args(pids, argc, argv);

	for (i = 0; i < proc_count; i++)
	{
		printf("-->%d. %d\n", i+1, pids[i]);
	}

	retval = pipe(pipe_descritors);
	pid = fork();
	if(pid == 0)
	{
		close(pipe_descriptors[0]);
		ovd(pipe_descriptors[1], pids, proc_count);
	}
	else
	{
		close(pipe_descriptors[1]);
		ovc(pipe_descriptors[0]);
	}

}

