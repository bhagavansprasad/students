#include<stdio.h>
float fact(int);
main()
{
	float a,n=3.4;
	a=Fact(n);
	printf("%f",a);
}
float fact(int m)
{	
	int f=1,i;
	for(i=1;i<=m;i++)
		f=f*i;
	return(f);
}
