#include <stdio.h>
#include <unistd.h>

main()
{
	char *temp[4];
	temp[0] = "pr71";
	temp[1] = "hello";
	temp[2] = "viswa";
	temp[3] =  (char *)0;
	printf("i am parent my pid is %d \n", getpid());
	execvp(temp[0],temp);
	printf("this will not print\n");
}
