#include <stdio.h>
int aatoi(char *a);
main()
{
	char str[12]="9a87";
	int val=0;
	val=aatoi(str);
	printf("aatoi :%d\n", val);
	printf("atoi  :%d\n", atoi(str));
}








