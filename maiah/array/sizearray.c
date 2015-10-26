#include <stdio.h>
#include <unistd.h>
main()
{
	int a[20]={2,5,9,8,7,4,6,1,3};
	int *p;
	int *q;
	int n;
	q=(int *)(&a+1);
	p=(int *)a;
	n=q-p;
	printf("%u\n",p);
	printf("%u\n",q);
	printf("the size of the array is:%d\n",n);
}
