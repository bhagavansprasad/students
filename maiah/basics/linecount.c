#include <stdio.h>
#include <fcntl.h>
main()
{
	int lc=0;
	char buff[100]="i am in the institute\n"
		"i am executing the programs\n"
		"tomorrow i am going to attend the interview\n\0";
	lc=alinecount(buff);
	printf("the line count is: %d\n",lc);
	return 0;
}
int alinecount (char *p)
{
	int lc=0,i=0;
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]=='\n')
			lc=lc+1;
	}
	return lc;
}
