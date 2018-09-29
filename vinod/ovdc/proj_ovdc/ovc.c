#include "defs.h"

extern int count;

void ovc(int fdr)
{
	int i = 0;
	int cpu_val = 0;
	auto int db_jiffy[256][2];
	printf(" count : %d\n", count);
	//memset(db_jiffy, 0, sizeof(int)*(256)*(2));
	printf("ovc : after memset\n");
	for(i=0 ; i<count ; i++)
	{
		if(read(fdr, &data2, sizeof(data2)) < 0)
		{
			perror("Error in reading from pipe : ");
			exit(1);
		}
		printf("ovc : after entering for and read pipe\n");
		if(data2.pid == 0)
		{
			printf("ovc : after if\n");
			continue;
		}
		else
		{
			db_jiffy[i][0] = data2.pid;
			if(db_jiffy[i][1] != 0)
			{	
				cpu_val = data2.jiffy - db_jiffy[i][1];
				db_jiffy[i][1] = cpu_val;
			}
			else
				db_jiffy[i][1] = data2.jiffy;
			printf("--> CPU occupancy of process %d is : %d\n",db_jiffy[i][0],cpu_val);
			ctrlmsg(cpu_val, data2.pid);
		}
	}
}
