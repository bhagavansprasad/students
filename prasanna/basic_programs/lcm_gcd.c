#include<stdio.h>

int gcd(int m,int n)
{
	int r;
	while(n!=0)
	{
		r=m%n;
		m=n;
		n=r;
	}
	return m;
}


void main()
{
	int lcm,m,n,gcd_value;
	printf("enter the value of m and n");
	scanf("%d %d",&m,&n);
	gcd_value=gcd(m,n);
	printf("GCD of %d and %d is: %d\n", m, n, gcd_value);

	lcm=m*n/gcd_value ;
	printf("LCM of %d and %d is :%d\n", m, n, lcm);
}
