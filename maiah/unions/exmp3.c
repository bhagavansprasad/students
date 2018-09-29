#include "stdio.h"
union num
{
	int i;
	long int l;
	float f;
	double d;
};
main()
{
	union num a[10];
	a[4].i=12;
	a[5].l=25410;
	a[6].f=6.22;
	a[7].d=28.72;
	printf("%d\n",a[4].i);
	printf("%ld\n",a[5].l);
	printf("%f\n",a[6].f);
	printf("%lf\n",a[7].d);
	
}
