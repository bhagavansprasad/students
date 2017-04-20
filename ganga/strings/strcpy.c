#include<stdio.h>
#include<string.h>

int main()
{
 char src[100] = " aura networks";
 char dest[100];
	int  i;

	for(i = 0 ; src[i] != '\0' ; i++)
	{
		dest[i] = src[i];
	}
     dest[i] = '\0';

	printf("copy of the string %s is %s\n", src, dest);

	return 0;
}
