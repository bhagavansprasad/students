#include<stdio.h>
#include<string.h>
main()
{
	char a[20]="hello";
	char b[20];
	int n=3;
	astrncpy(a,b,n);
	printf("b=%s\n",b);
}
