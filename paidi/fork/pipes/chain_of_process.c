#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
main()
{
  pid_t pid;
  while(1)
  {
    pid = fork();
	if(pid > 0)
	{
	 printf("parent process\n");
	  sleep(100);
	  exit(1);
	}
  }
}
