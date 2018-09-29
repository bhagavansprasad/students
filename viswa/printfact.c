#include<stdio.h>
 long double fact_value_print(int );
main()
{
	long double n=20,t=0,a,i;
	for(i=1;i<=n;i++)
	{
		t=fact_value_print(i);
		printf("\t%Lf\n",t);
	}
}
 long double fact_value_print(int x)
{
	long double i,f=1;
	for(i=1;i<=x;i++)
	{
		f=f*i;
	}
	return(f);
}
