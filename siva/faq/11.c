#include<stdio.h>
main()
{
	char a[5][5],flag;
	a[0][0]='A';
	flag = ((a==*a) &&(*a==a[0]));
	printf("%d\n",flag);
}
