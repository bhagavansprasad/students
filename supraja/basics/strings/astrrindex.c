#include<stdio.h>
#include<string.h>
int *astrrindex(char *s,int n)
{
	int i;
	for(i=len_s(s);i>=0;i--)
	{
		if(s[i]==n)
         break;
	}
	return (i);
}
int main()
{
    int t;
	char s1[]="aura networks";
	char ch='a';
	t=astrrindex(s1,ch);
	printf("%d\n",t);
}
