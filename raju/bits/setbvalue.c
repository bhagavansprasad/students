#include<stdio.h>

#define SET_BIT_VALUE(n,pos,value) ((value==1)?(n)|(1<<(pos)-1):(n)&(~(1<<pos-1)))

main()
{
	
	int a=10,t;
	
	t=SET_BIT_VALUE(a,3,1);

	printf("t:%d\n",t);

}	

