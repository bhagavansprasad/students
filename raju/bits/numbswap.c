#include<stdio.h>

#define GET_BIT_VALUE(n,pos) ((n)&(1<<(pos)-1)?1:0)

main()
{

	int a=10,b=16,i,ta,tb,swap=0;

	
	for(i=8*sizeof(a);i>=1;i--)
	{

		ta=GET_BIT_VALUE(a,i);

		tb=GET_BIT_VALUE(b,i);

		if(ta!=tb)
			swap++;
	
	}


	printf("no. of swaps:%d\n",swap);
}

