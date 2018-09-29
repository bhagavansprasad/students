
#include<stdio.h>
main()
{
	int r = 1;
	int n;

	printf("enter the number \n");
	scanf ("%d",&n);
	r=r*10 + n%10;
	n=n/10;
	r=r*10 + n%10;
	n=n/10;
	r=r*10 + n%10;
	n=n/10;

	printf("reverse number is %d\n",r);
}
