#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int join(char ** , char **);
main()
{
	char *one[3],*two[2];
	int ret;
	one[0] = "ls";
	one[1] = "-li";
	one[2] = (char *)0;

	two[0] = "sort";
	two[1] =(char)0;
	ret = join(one ,two);
	printf("join returned %d\n",ret);
	exit(0);
}


int join( com1 , com2)
char *com1[],*com2[];
{
	int p[2];
	int status;
	switch( fork())
	{
		case -1 :
			perror("Error");
		case 0 :
			break;
		default : 
			wait(&status);
			return status;
	}
	if( pipe(p) < 0)
		perror("pipe call in join ");
	switch(fork())
	{
		case -1 :
					perror(" 2nd fork call in join ");
		case 0 : 
					close(1);
					dup(p[0]);
					close(p[0]);
					close(p[1]);
					execl("/bin/sort", com1[0] , com1[1], com1[2]);
					perror("1st execvp call in join");
		default : 
					close(0);
					dup(p[0]);
					close(p[0]);
					close(p[1]);
					execl("/bin/sort", com2[0] , com2[1]);
					perror("2nd execvp call in join");

				
	}
}
