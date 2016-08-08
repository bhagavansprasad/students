#include <stdio.h>
#include "defs.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
struct  giffs_db giffs_data[10];

//extern int noe=0;

int get_fd_by_pid (int pid)
{
	char filename[124];
	int fd=-1, i;

	for(i = 0 ; i <= noe; i++)
	{
		if(giffs_data[i].pid == pid)
		{
			if(giffs_data[i].fd != -1)
				return giffs_data[i].fd;
			else
			{
				sprintf(filename, "/proc/%d/stat", pid);
				OVDC_DEBUG("-->filename :%s\n", filename);

				fd = open(filename, O_RDONLY, 0);
				giffs_data[i].fd = fd;

				return giffs_data[i].fd;
			}
		}
		printf("no process exist:%d\n",pid);
		
		giffs_data[i].pid = pid;
		noe++;
		return -1;
	}
}

