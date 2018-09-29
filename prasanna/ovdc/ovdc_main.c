#include<stdio.h>
#include"defn_ovdc.h"


int main()
{
	int p[2],p_id;
	
	pipe(p);
	p_id = fork();
	printf("Parent process ID: %d\n",getppid());
	if(p_id == 0)
	{
		while(1)
		{
			ovd(p[1]);
			sleep(1);
		}
	}
	else
	{
		while(1)
		{
			ovc(p[0]);
		}
	}
		
}
