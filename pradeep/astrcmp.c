#include<stdio.h>
int main()
{
	char str1[100]="PRADEEP";
	char str2[100]="PRADEEP";
	int t;
	t=astrcmp(str1,str2);
	if(t==1)
		printf("same\n");
	else
		printf("not same\n");
}
int astrcmp(char *s,char *d)
{
	int i;
	for(i=0;s[i]==d[i];i++)
	{	
		if(s[i]=='\0')
			return 1;
	}
	return 0;
}
