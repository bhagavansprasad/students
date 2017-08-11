#include <stdio.h>
main()
{
	int a[5]={3 , 4 ,5 , 6 ,7 };
	//int *ip=&a;
	//char *cp=&a;
	printf("%p\n",a);
	printf("%p\n",&a[0]);
	printf("%p\n",&a);
	printf("%d\n",a[0]);

	printf("%p\n",a+1);
//	printf("%p\n",&(*(a+1)));
	printf("%p\n",&a[1]);
	printf("%d\n",a[1]);

printf("%p\n",&a+1);
printf("%p\n",(&a)+1);
printf("%p\n",&(a+1));
}

