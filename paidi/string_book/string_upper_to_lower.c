#include<stdio.h>
#include<string.h>
int main()
{
	char str[20]="PAIDIKUMAR";
	int i;
	printf("The string is->%s",str);

	for(i=0;i<=strlen(str);i++)
	{
		if(str[i]>=65&&str[i]<=90)
			str[i] = str[i]+32;
	}
	printf("\nThe string in lower case is->%s\n",str);
}
