#include <stdio.h>
int main()
{
	int i,t;
	char buff[100]="  !@#$%HEllO WORLd  ";
	char buff1[100]=" ";
	t=astrtogglecase(buff,buff1);
	printf("%s",buff1);
}
int astrtogglecase(char *s,char *d)
{
	int i=0,c;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]<65 || s[i]>122)
		{
			d[i]=s[i];
		}
		if(s[i]>=65 && s[i]<=90)
		{
			d[i]=s[i]+32;
		}
		if(s[i]>=97 && s[i]<=122)
		{
			d[i]=s[i]-32;
		}
	}
}
