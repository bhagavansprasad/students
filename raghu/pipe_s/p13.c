#include <stdio.h>
#include "def.h"

main()
{
	int pc[2],ps[2];
	int pid;
	char *msg1 = "what are you doing ?";
	char *msg2 = "what are you sharing ?";
	char *msg3 = "what are you upto now ?";
	char *msg4 = "what else you want ?";
	char *msg5 = "where are you going ?";
	char *msg6 = "none of your bussines";
	char buff1[SIZE];
	char buff2[SIZE];
	pipe(pc);
	pipe(ps);
	pid = fork();
	
	if(pid > 0)
	{
		printf("------>parent<-----------\n");
		write(pc[1],msg1,SIZE);
		write(pc[1],msg2,SIZE);
		write(pc[1],msg3,SIZE);
		
		read(ps[0],buff2,SIZE);
		printf("the parent read value %s\n",buff2);
		
		write(pc[1],msg4,SIZE);
		write(pc[1],msg5,SIZE);

		//read(ps[0],buff2,SIZE);
		//printf("the parent read value %s\n",buff2);

	}
	else
	{
		printf("------->child<----------\n");
		read(pc[0],buff1,SIZE);
		printf("the first read value %s\n",buff1);
		read(pc[0],buff1,SIZE);
		printf("the second read value %s\n",buff1);
		
		write(ps[1],msg6,SIZE);

		read(pc[0],buff1,SIZE);
		printf("the third read value %s\n",buff1);
		read(pc[0],buff1,SIZE);
		printf("the fourth read value %s\n",buff1);
		read(pc[0],buff1,SIZE);
		printf("the fiveth read value %s\n",buff1);
		
	}

}
