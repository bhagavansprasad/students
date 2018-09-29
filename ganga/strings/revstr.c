#include<stdio.h>
void main()
{
	int i, j, k;
	char str[100] = "ramesh";
	char rev[100];
	for(i = 0; str[i] != '\0'; i++);
	{
		k = i-1;
		printf("%d%d\n", k, i);
	}
	for(j = 0; j <= i-1; j++)
	{
		rev[j] = str[k];
		k--;
	}
	printf("The reverse string is %s\n", rev);
}
