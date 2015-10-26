#include "fact.h"

int factorial(int n)
{
	int i,f=1;
//	printf("ENTERED NUMBER IS :%d\n",n);
	
	if(n==0)
	{
	 	printf("Factorial value is %d\n", n);
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		f=f*i;
	//	printf("FACTORIAL VALUE IS %d  < %i >\n:", f,i);

	}
//	printf("FACTORIAL VALUE IS %d\n:", f);
	return f;
}
