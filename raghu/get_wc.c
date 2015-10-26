/*function for word count*/
#include <stdio.h>
int get_wc(char * buff)
{
	int wc=0,i;
	for(i=0;buff[i]!='\0';i++)
	{
		if((buff[i]!=' ')&&((buff[i+1]==' ')||
		(buff[i+1]=='\0')||(buff[i+1]=='\n')))
			wc++;
			//printf("wc--->%d\n",wc);
			}
		//	printf("%d",wc);
	wc=wc-1;
	return wc;
}

/*function for charector count*/
int get_char_count(char *buff)
{
	int cc=0,i;
	for(i=0;buff[i]!='\0';i++)
	{
		if((buff[i]!=' ')||(buff[i]==' '))
		cc++;
	}
//	printf("%d",cc);
	return cc;
}
