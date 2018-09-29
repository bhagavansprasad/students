#include<stdio.h>

#define GET_BIT_COUNT(n,pos,count) ((n)&1<<(pos)-1?++count:count)

main()
{

	int i,a=63,cnt=0;

	for(i=8*sizeof(a);i>=1;i--)
	{

		cnt=GET_BIT_COUNT(a,i,cnt);

	}

	printf("count:%d\n",cnt);

}	
