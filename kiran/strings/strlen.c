#include <stdio.h>
#include <string.h>
int i = -1;
int main()
{
	char s[50]= {"hihello"};
	int len = 0;
	len = astrlen(&s);
	printf("strlen = %d\n",len);
}

int astrlen(char *s)
{	
	i++;
	if(s[i]=='\0')
	{
		return i;
	}
	else
	{
	return (i+astrlen(&s));
	}
	
}
