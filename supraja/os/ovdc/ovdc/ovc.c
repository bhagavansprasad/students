#include <stdio.h>
int data_base[4][2],i;
int store_into_db(int pid,int giffs)
{
	for(i=0;i<4;i++)
	{
	if(data_base[i][0]==pid)
	 return giffs-data_base[i][1];
	}
}
int ovc(int rfd)
{

	int cpu_occ;
	for (;;)
	{
		int r;
		//read_giffs_from_pipe(rfd, &pid, &giffs);
		r=read(rfd,data_base,sizeof(data_base));
		for(i=0;i<4;i++)
		{
			cpu_occ = store_into_db(data_base[i][0],data_base[i][1]);
			printf("---------->pid %d\tcpu occupency %d\n",data_base[i][0],cpu_occ);
	//		take_action(pid, cpu_occ);
	//		clean_up_db();
		}
	}
}
