#include<stdio.h>

#define SET_BIT_VALUE_ON(n,pos) (n=(n)|(1<<(pos)-1))

main()
{
	
	int a=10,n;
	
	n=SET_BIT_VALUE_ON(a,3);

	printf("n:%d\n",n);

}	

