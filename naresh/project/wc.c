#include<stdio.h>
main()
{
	int wd;
	char buff[100]="hi sunny ";
	wc=astrwc(buff);
	printf("word count is %d",wc);
	return 0;
}
int astrwc(char *p)
{
	int i=0,wc=0;
	for(i=1;p[i]!='\0';i++)
	{
		if(p[i]!=' ')&&if(p[i]==' ')
			wc=wc+1;
	}
	return wc;
}
