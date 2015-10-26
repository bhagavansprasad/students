#include <stdio.h>
main()
{
	int a[5]={1,2,3,4,5};
	int *p=a;
	int i;
	p++;
	for(i=0;i<5;i++)
	printf("%d\n",a[i]);
}
