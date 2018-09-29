#include<stdio.h>
main()
{
	int a=0x12131415;
	short int *sh=(short int *)&a;
	int i=0,n=2;
	for(i=0;i<n;i++)
	{
		printf("%x",*sh);
		sh++;
		}
}
