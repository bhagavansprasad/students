#include<stdio.h>
main()
{
	int a=111,x=0;
	x=is_arm(a);
	if(x==0)
		printf("\n not armstrong ");
	else
		printf(" \n armstrong");
}
int is_arm(int a)
{
	int t,i,r,s=0;
	t=a;
	for(i=1;i<=3;i++)
	{
		r=a%10;
		a=a/10;
		s=s+(r*r*r);
	}
	if(s==t)
		return (1);
	else
		return (0);
}
