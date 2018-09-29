#include <stdio.h>
float add(float,int);
float sub(float,int);
float mul(float,int);
float div(float,int);
main()
{
	int i,b=4.5;
	float a=7;
	float (*fp[])(float,int)={add,sub,mul,div};
	char *operation[]={"Add","Sub","Mul","Div"};
	for(i=0;i<4;i++)
	printf("%s :%f\n",operation[i],(*fp[i])(a,b));
	return 0;
}
float add(float a,int b)
{
	return a+b;
}
float sub(float a,int b)
{
	return a-b;
}
float mul(float a,int b)
{
	return a*b;
}
float div(float a,int b)
{
	return a/b;
}
