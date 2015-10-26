#include"task_headre.h"

main(int argc,char *argv[])
{

	int jiffs=0,interval,i;
	int array[4][2]={{0,0}};
	
	array[0][0] = my_atoi(argv[1]);
	array[1][0] = my_atoi(argv[2]);
	array[2][0] = my_atoi(argv[3]);
	array[3][0] = my_atoi(argv[4]);	
	interval = my_atoi(argv[5]);

	printf("\t PID \t  Cpu occupency  \n");
	for(;;)
	{

		for(i=0;i<4;i++)
		{
			if((jiffs = read_jiffs_by_pid(array[i][0])) == -1)
			{
				printf("Pid does not exist\n");
				return 1;
			}
			printf("\t %2d \t     %4d \n",array[i][0],(jiffs-array[i][1])/interval);


			array[i][1] = jiffs;
		//	printf("preve: %d\t cjiff :%d\n",array[i][1],jiffs);
			
		}
		sleep(interval);
	}
	
}

