#include <stdio.h>
#include <string.h>
main()
{
	int f;
	char s1[100]="hi i am raghu";
	char s2[100]="hi i am Raghu";
	f=str_cmp(s1,s2);
	printf("%d",f);
}
