#include <stdio.h>
#include<fcntl.h>
main()
{
	int wc=0;
	char buff[100]="in bangalore there many companies offer for jobs to freshes\0";
	wc=awordcount(buff);
	printf("%d",wc);
	return 0;
}
int awordcount(char *p)
{
	int i=0,wc=1;
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]==' ')
		wc=wc+1;
	}
	return wc;
}
