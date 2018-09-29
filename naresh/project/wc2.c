#include "stdio.h"
#include "fcntl.h"
main()
{
	int wc;
	char buff[100]="hi hello    how are u";
	wc=astrwc(buff);
	printf("word count is :%d\n",wc);
}
int astrwc(char *p)
{
	int i=0,s,wc=1;
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]==' '&&p[i]!=' ')
			wc=wc+1; 
	}
	return wc;
}
