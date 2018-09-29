#include<stdio.h>
main()
{
	int a=10;
	int *p;
	p=&a;
	printf("%d\n",*p);
	*p=20;
	printf("%d\n",*p);
	printf("%d\n",p);
	p=p+1;
	printf("%d\n",p);
	p++;
	printf("%d\n",p);
}
