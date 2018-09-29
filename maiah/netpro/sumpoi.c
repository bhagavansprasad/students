#include<stdio.h>
main()
{
	int a[10]={1,2,3,6,5,6,8,9,7,4};
	int i,sum=0;
	int *p;
	p=a;
	for(i=0;i<10;i++)
	{
	sum = sum + (*p);
	p++;
	}
	printf("the sum of the array is:%d\n",sum);
}
