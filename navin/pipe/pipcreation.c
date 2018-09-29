#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

main()
{
   int fd[2];
   pipe(fd);
   int pid=fork();
   int nbytes;
   char string[25]="Naveen Kumar";
   char buffer[100];
    
   if(pid==0)
   {	
   		close(fd[0]);

        write(fd[1],string,(strlen(string)+1));
		printf("Child pid:%d \n",getpid());
		//exit(0);
	}
	else 
	{
	//	wait(2);
    //		sleep(2);
	   close(fd[1]);
	   nbytes=read(fd[0],buffer,sizeof(buffer));
	   printf("RECEIVED STRING : %s\n",buffer);	
	   printf("Parent pid:%d\n",getpid());

	}   



}
