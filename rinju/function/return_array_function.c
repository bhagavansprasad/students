#include<stdio.h>
int* add(int n)
{
	int i;
	static int a[12];
	for(i=0;i<5;i++)

		a[i]=i;
	return a;
}
main()
{
	int *p,i;
	p=add(10);
	for(i=0;i<5;i++)
		printf(" %d ",p[i]);
}
