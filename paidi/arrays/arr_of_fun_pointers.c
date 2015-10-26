#include <stdio.h>
#include <string.h>

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

int main()
{
	int i,b=10;
	float a=10.5;
	float (*fp[])(float,int)={add,sub,mul,div};
#if 0
	float (*fp[4])(float,int);
	fp[0]=add;
	fp[1]=sub;
	fp[2]=mul;
	fp[3]=div;
#endif
	char *operation[] = {"add    ","subtract","multiply","divide"};
	for(i=0;i<4;i++)
		printf("%s          	:%f\n",operation[i],(*fp[i])(a,b));
	return 0;
}

