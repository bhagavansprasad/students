#include <stdio.h>
main()
{
	int a[3][3] = {1,2,3,4,5,6,7,8,9};
	printf("**a+0-->%d\n",**a+0);
	printf("**a+1-->%d\n",**a+1);
	printf("**a+2-->%d\n",**a+2);
	printf("**a+3-->%d\n",**a+3);


	printf("************\n");
	printf("sizzeof(&a)-->%d\n",sizeof(&a));
	printf("sizzeof(&a+1)-->%d\n",sizeof(&a+1));
	printf("sizzeof(a+1)-->%d\n",sizeof(a+1));
	printf("sizzeof(*a+1)-->%d\n",sizeof(*a+1));
	printf("sizeof(a)-->%d\n",sizeof(a));
	printf("sizeof(*a)-->%d\n",sizeof(*a));
	printf("sizeof(**a)-->%d\n",sizeof(**a));
	printf("************\n");




	printf("a-->%u\n",a);
	printf("*a-->%u\n",*a);
	printf("&a-->%u\n",&a);
	printf("*a+1-->%u\n",*a+1);
	printf("a+1-->%u\n",a+1);
	printf("a+1-->%u\n",a[1]);
	printf("*a+2-->%u\n",*a+2);
	printf("*a+3-->%u\n",*a+3);
	printf("&a+1-->%u\n",&a+1);
	printf("&a+2-->%u\n",&a+2);
}	
