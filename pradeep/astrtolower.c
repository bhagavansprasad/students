#include<stdio.h>
int main()
{
int t;
	char str1[100]="HELLO WORLD:w
	";
	char str2[100]=" ";
	t=astrtolower(str1,str2);
	printf("%s",str2);
}
int astrtolower(char *s,char *d)
{
int i,c;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>=65 || s[i]<=90)
		{
			c=s[i]+32;
		}
		d[i]=c;
	}
}
