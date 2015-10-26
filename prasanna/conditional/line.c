#include<stdio.h>

main()
{
	int i,a[10],n = 8;
	for(i = 0;i < n;i++)
		printf(" %6d %c",a[i],(i%10 == 9 || i == n-1)? '\n':' ');
}
