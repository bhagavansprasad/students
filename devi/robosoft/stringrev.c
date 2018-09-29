#include <stdio.h>
#include "string.h"
void astrrev(char *str)
{
	int i,j,len;
	for(len=0;str[len]!='\0';len++);
		printf("length-->%d\n",len);

	for(i=0,j=len;i<=len/2;i++,j--)
	{
		str[i] = (str[i]+str[j]);
	printf("%c\n",str[i]);
		str[j] = str[i]-str[j];
	printf("%c\n",str[j]);
		str[i] = str[i]-str[j];
	printf("%c\n",str[i]);
	}
	printf("%s\n",str);
}
main()
{
	char str[10]="devi";
	astrrev(str);
}
