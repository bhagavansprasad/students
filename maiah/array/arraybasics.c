#include <stdio.h>
#include <unistd.h>
main()
{
	int a[10]={2,5,6,8,4,2};
	int *p=a;
	printf("%u\n",a);
	printf("%u\n",p);
	printf("%d\n",*p);
	printf("%d\n",*a);
	printf("%u\n",p+1);
	printf("%u\n",a+1);
	printf("%d\n",p[1]);
	printf("%d\n",a[1]);
	printf("%u\n",&a);
	printf("%u\n",*&a);
	printf("%d\n",**&a);
	printf("%u\n",&a+1);
	printf("%u\n",&a[1]);
	printf("%u\n",&a[1]+1);
}
