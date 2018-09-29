#include <stdio.h>
main()
{
	int i = 0, j = 0, pid;
	pid = fork();
	
	if(pid == 0)
	{   
		for(i = 0; i<50; i++)
		{
			printf(" Child: %d\t", i);
		}
	}
	else if(pid > 0)
	{
		for(j = 0; j< 50; j++)
		{  
		
			printf("Parent: %d\t", j);
		}
	
	}
}
