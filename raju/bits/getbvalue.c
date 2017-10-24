#include<stdio.h>

#define GET_BIT_VALUE(n,pos) ((n)&(1<<(pos)-1)?1:0)

main()
{

	int a=10,t,mask=10;

	t=GET_BIT_VALUE(a,3);

	printf("t:%d\n",t);
}

