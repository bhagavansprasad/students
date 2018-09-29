#include<stdio.h>
#include<string.h>
int my_var_supraja = 0;

char *astrncat(char *s,char *d,int m)
{
	int i,n=len_s(s);
	for(i=0;i<=len_s(d)&& s[i]!='\0'&&i<=m;i++)
	{
		s[i+n]=d[i];
	}
	    s[i+n]='\0';
      printf("%s\n",s);
	return (d);
}
int main()
{
	char s1[]="aura";
	char s2[]="networks";
	astrncat(s1,s2,3);
	//printf("%s\n",);
}
