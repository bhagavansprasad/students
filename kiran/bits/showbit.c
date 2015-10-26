/*#include <stdio.h>
int main()
{
	unsigned int n = 10, mask = 1, i;
	mask = mask << (32-1);
	printf("sizeof(n = %d) is %d BYTES & each bit value is====> ",n,(int)sizeof(n));
	while(mask > 0) 
	{
		if((n&mask)!=0)
		{
			printf("1 ");
		}
		else
		{
			printf("0 ");
		}
		mask = mask/2;
	}
	printf("\n");
}*/

/*#include <stdio.h>
int main()
{
	unsigned int n = 300, mask = 1, i = 0;
	for(i = 32; i > 0 ; i--)
	{
		mask = 1;
		mask = mask<<(i-1);
		if((n & mask)!= 0)
		{
			printf("1 ");
		}
		else 
		{
			printf("0 ");
		}
	}
}*/

#include <stdio.h>
int main()
{
	unsigned int n = 300, mask = 1, i = 0,a;
	for(i = 32; i > 0 ; i--)
	{
		mask = 1;
		printf("%d ",((n & (mask<<(i-1)))?1:0));
	}
}
