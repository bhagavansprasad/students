#include "defs.h"
int count;
int proc[256];

void ovd(int fdw)
{
	int i = 0;
	int fd = 0;
	int wrval = 0;
	int jiffy = 0;

	count = get_proc_list(proc);
	for(i=0 ; i<count ; i++)
	{
		fd = get_fd(proc[i]);

		if(fd < 0)
		{
			//printf("--> P : fd :%d\n", fd);
			data1.rpid = proc[i];
			data1.pid = 0;
			data1.jiffy = 0;
			if((wrval = write(fdw, &data1, sizeof(data1)) < 0))
			{
				perror("Error in writing to pipe : ");
				exit(1);
			}
			//printf("--> P : wrval :%d\n", wrval);
			continue;
		}
		else
		{
			//printf("--> p: fd :%d\n", fd);
			jiffy = get_jiffy(fd);
			//printf("--> P :jiffy %d\n", jiffy);
			data1.pid = proc[i];
			data1.rpid = 0;
			data1.jiffy = jiffy;
			if(write(fdw, &data1, sizeof(data1)) < 0)
			{
				perror("Error in writing to pipe : ");
				exit(1);
			}
		}
	}

}
