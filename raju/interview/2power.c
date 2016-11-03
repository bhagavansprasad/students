#include<stdio.h>

#define GET_BIT_VALUE(n,pos) (n&1<<(pos)-1?1:0)

main()
{

	int a=128,i,power,t;

	for(i=32;i>=1;i--)
	{
		
		t=GET_BIT_VALUE(a,i);
		
		if(t==1)
		{
			power=1<<i;
		
			break;
		}	

	}	
	printf("2 power:%d\n",power);

}	
	
