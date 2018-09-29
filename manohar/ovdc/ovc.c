#include "define.h"

int element=0;
int db[4][2]= {{0,0}};

int ovc(int rfd)
{
	int i,j,cpu_occupancy,ret_val;
	list data; 

	while(1)
	{
		ret_val = read(rfd, &data, sizeof(data));

		for(i=0; i< element; i++)
		{
			if(data.pid == db[i][0])
			{
				if(data.giffy == -1)  // delete pid from db
				{
					for(j=i; j<element; j++)
					{
						db[j][0]=db[j+1][0];
						db[j][1]=db[j+1][1];
						element--;
					}
				}
				cpu_occupancy = data.giffy-db[i][1];
				printf("pid----->%d\tcpu_occupancy========>%d\n",db[i][0],cpu_occupancy);

				statistics(cpu_occupancy);

				db[i][1]= data.giffy;        //update

				break;
			}
		}
		if(i==element)  //insert
		{
			if(data.giffy != -1)
			{
				db[i][0]= data.pid;
				db[i][1]= data.giffy;
				element++;
			} 
		}
	}
}

int statistics(int usage)
{
if(usage > 20 && usage < 30)
printf("------>low risk\n");
if(usage > 30 && usage < 50)
printf("------>cause risk\n");
if(usage > 50 && usage < 60)
printf("------>warning\n");
if(usage > 60)
printf("------>suspended \n");
return 0;
}



/*
   while(1)
   {
   read 
   get_index_by_pid
   if it is a new entry
   make new entry
   update the existing entry and caliculate cpuocc
   take necessary actions
   }
 */
