#include<stdio.h>
#include<string.h>

int trim1(char s[])
{
	int n;
	for(n = strlen(s)-1;n>=0;n--)
		if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;
	
	s[n+1] = '\0';
	return n;
}
main()
{
	char str[50] ="pra kumar y            ";
	printf("length : %d\n",strlen(str));
	printf(" %d\n   ",trim1(str));
}
