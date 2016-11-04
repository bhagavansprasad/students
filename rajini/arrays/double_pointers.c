#include<stdio.h>
main()
{
	int a[][5] = {
			{1,2,3,4,5},
			{6,7,8,9,10},
			{11,12,13,14,15}
		      };
	printf("a is : %u\n",a);
	printf("&a is : %u\n",&a);
	printf("&&a is : %u\n",&&a);
	printf("a+1 is : %u\n",a+1);
	printf("&a+1 is : %u\n",&a+1);
	printf("a[1][2] is : %u\n",a[1][2]);
	printf("&a[1][2] is : %u\n",&a[1][2]);
	printf("a[1][2]+1 is : %u\n",a[1][2]+1);
	printf("a[1][2]+1 is : %u\n",&a[1][2]+1);
	printf("a[2] is : %u\n",a[2]);
	printf("&a[2] is : %u\n",&a[2]);
	printf("&a[2]+1 is : %u\n",&a[2]+1);
	printf("*a[2] is : %u\n",*a[2]);
	printf("a[1][2] is : %u\n",a[1][2]);
	printf("&a[1] is : %u\n",&a[1]);
	printf("&a[1]+1 is : %u\n",&a[1]+1);
	printf("&a+1 is : %u\n",&a+1);
	printf("&a[1][2] is : %u\n",&a[1][2]);
	printf("&a+1 is : %u\n",&a+1);
	printf("&a[1][2]+1 is : %u\n",&a[1][2]+1);
}
