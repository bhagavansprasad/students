#include<stdio.h>

#define SET_BIT_VALUE_OFF(n,pos) (n=(n) & (~(1<<(pos)-1)))

main()
{
	
	int a=10,n;
	
	n=SET_BIT_VALUE_OFF(a,4);

	printf("n:%d\n",n);

}	

