#include<stdio.h>
main()
{
int *a={1,2,3,4};
int *b={6,7,8,9,10};

	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
	printf("elements is %d\n",*a);

}
//this program is not valid
