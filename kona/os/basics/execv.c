#include <stdio.h>
main()
{

	char *temp[3];
	temp[0]="ls";
	temp[1]="-l";
	temp[2]=(char*)0;
	execv("execv.c",temp);
	printf("this will not print\n");
}
