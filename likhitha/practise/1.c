#include <stdio.h>
main()
{
	char *p;
	int a[]={ 3 , 4,5 };
	p=&a;
	p[0]=(int *)malloc(2*(sizeof(int)));
	printf("%d\n",p[0]);
}
