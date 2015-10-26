#include<stdio.h>
int get_word_count(char *buff)
{
	int c=0,i;
	for(i=0;buff[i]!='\0';i++)
	{
	if ((buff[i]!=' ')&&((buff[i+1]==' ')||(buff[i+1]=='\n')))
	c++;
	
	}
	//c=c-1;
	printf("%d\n",c);
	return c;
}
