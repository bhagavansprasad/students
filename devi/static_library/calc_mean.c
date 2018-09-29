#include <stdio.h>
#include "calc_mean.h"


main()
{
	double p=10,q=20;
	double x;
	x=mean(p,q);
	printf("x=%lf\n",x);
}


double mean(double a,double b)
{
	return (a+b)/2;
}
