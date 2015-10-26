#include "stdio.h"
#define GET_BIT_VALUE(n,bpos)(a&1<<(bpos-1)?0:1)

main()
{
	int m = 1,i = 0,a = 7,bpos = 32;
	int showbit(int n)
	{
		for(i = 1; i <= 32; i++)
		{
			printf("%d\n",GET_BIT_VALUE(n,i));
		}
	}
}
