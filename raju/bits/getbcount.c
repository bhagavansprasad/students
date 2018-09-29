#include<stdio.h>

#define GET_BIT_VALUE(n,pos) ((n)&1<<(pos)-1?1:0)

main()
{

	int i,t,a=14,count=0;

	for(i=8*sizeof(a);i>=1;i--)
	{

		t=GET_BIT_VALUE(a,i);

		if(t==1)
			count++;

	}

	printf("count:%d\n",count);

}	
