#include<stdio.h>
float square(float);
main()
{
	float a=6.2,b=1;
	b=square(a);
	printf("square=%f\n",b);
}
float square(float x)
{
	float y;
	y=x*x;
	return y;
}
