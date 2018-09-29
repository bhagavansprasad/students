#include "stdio.h"
void display (int n);
main()
{
	int a[]={10,20,30,40,50};
	int i;

	for( i = 0 ; i < 5 ; i++)
	{
		display(a[i]);
	}
}

void display (int n)
{
	printf("%d\n",n);
}
