#include<stdio.h>
#include<string.h>

char reve(char *str)
{

	char temp;
	char *s = str + strlen(str)-1;

	while(s > str)
	{
		temp = *s;
		*s = *str;
		*str = temp;
		s--;
		str++;
	}
	
}
int main()
{
	char str[20] = "Prasanna kumar";
	
	printf("Before reverse: %s\n",str);
	reve(str);
	printf("After reverse:%s\n",str);
}
