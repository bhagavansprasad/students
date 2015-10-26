#include<stdio.h>
#include<string.h>
main()
{
	char a[20]="hello";
	char b[20];
	astrcpy(a,b);
	printf("b=%s\n",b);
}
