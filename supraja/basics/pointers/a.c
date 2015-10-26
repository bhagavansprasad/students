#include<stdio.h>
int main()
{
	char str1[]="ayygf";
	atoi(str1 );
}
atoi(char *s)
{
    int i;
	for(i=0;s[i]!='\0';i++)
	{
		printf("%d\n",s[i]);
	}
}
