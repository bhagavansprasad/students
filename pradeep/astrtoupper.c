#include<stdio.h>
int main()
{
	int t;
	char str1[100]="pradeep teja ";
	char str2[100]=" ";
	t=astrtoupper(str1,str2);
	printf("%s",str2);
}
int astrtoupper(char *s,char *d)
{
	int i,c;
	for(i=0;s[i]!='\0';i++)
		{
			if(s[i]>=97 || s[i]<=122)
			{
				c=s[i]-32;
			}
			d[i]=c;
		}
	}
