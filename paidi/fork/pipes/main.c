#include <stdio.h>
#include <stdlib.h>
#include<string.h>

main()
{
	int p1[2],p2[2],pid;
	pipe(p1);
	pipe(p2);
	pid = fork();
  for(;;)
   {
	if(pid == 0)
	{
		close(p1[1]);
        close(p2[0]);

		client(p1[0],p2[1]);
	}
	else
	{
		
		close(p1[0]);
		close(p2[1]);

		server(p2[0],p1[1]);
	}

	}
}
