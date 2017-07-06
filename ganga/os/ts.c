#include <stdio.h>

main()
{
	int i, pid = fork();
	
	if(pid == 0)
	{
		for(i = 0; i < 1000 ; i++)
			printf("%d\t", i);
	} 
	else
	{
		for(i = 0; i<1000 ; i++)
			printf("%d\t", i);
	} 
}  
