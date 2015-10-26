#include<stdio.h>
#include<string.h>
int *astrspn(char *s,char *d)
{
	int i,m=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='n'||s[i]=='e'||s[i]=='t')
		  m=m+1;
	}
	return (m);
}
int main()
{
    int t;
	char s1[]="aura networks";
	char s2[]="net";
	t=astrspn(s1,s2);
	printf("%d\n",t);
}
