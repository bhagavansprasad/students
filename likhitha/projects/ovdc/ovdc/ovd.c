#include <stdio.h>

int ovd(int wfd, int *pids, int proc_count)
{
	int pid, giffs;
	int i = 0;
	ovdc_db data;

	while(1)
	{
		for (i = 0; i < proc_count; i++)
		{
			printf("-->%d. %d\n", i+1, pids[i]);
			giffs = get_giffs_by_pid(pids[i]);

			data.pid = pids[i];
			data.giffs = giffs;

			write(wfd, &data, sizeof(data));

			//TODO:
			//Fill the sturcture with pid and giffs
			//write on to pipe
		}
		sleep(1)
	}


#if 0
	for( ; ; )
	{
		open();
		read();
		send(pid,giffs);
		sleep();
		return 0;
	}
#endif
}
