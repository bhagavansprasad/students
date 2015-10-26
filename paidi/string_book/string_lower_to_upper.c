#include<stdio.h>
#include <string.h>
int main()
{
	char str[20]="paidikumar";
	int i;
	printf("string in lower case-->%s\n",str);
	for(i=0;i<=strlen(str);i++)
	{
		if(str[i]>=97 && str[i]<=122)
			str[i] = str[i]-32;
	}
	printf("\nThe string in upper case is->%s\n",str);
}
