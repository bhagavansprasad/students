#include <stdio.h>
struct ovc_struct
{
	int pid;
	int giffs;
}ovc;
int data_base[100][3]={0},j;
static int count=0,i = 0;
int cpu_occ,rval;
int store_into_db(int pid,int giffs)
{
	if(i<4 && data_base[i][2]== 0)
	{


		data_base[i][0]=pid;
		data_base[i][1]=giffs;
		data_base[i][2]=1;
		i++;
		//count++;
		return 0;
	}
	else
	{
		for(j=0;j<4;j++)
		{
			if(data_base[j][0]==pid)
			{
				printf("---> new : %d\told:%d\n",giffs,data_base[j][1]);
				cpu_occ = giffs - data_base[j][1];
				printf("---> cpu occ: %d\n",cpu_occ);
				data_base[j][1]=giffs;
				return cpu_occ;
			}
		}

		return -1;
	}
}
int ovc_fun(int rfd)
{	
	int c =0;
	for (;c<12;c++)
	{
		//read_giffs_from_pipe(rfd, &pid, &giffs);
		rval=read(rfd,&ovc,sizeof(ovc));
		printf("--------->:read return value%d\n",rval);
		cpu_occ = store_into_db(ovc.pid,ovc.giffs);
		printf("--->in ovc.c file pid : %d\tcpu occ : %d\n",ovc.pid,cpu_occ);
		//		take_action(pid, cpu_occ);
		//		clean_up_db();
	}
}
