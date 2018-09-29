#include<stdio.h>                         
int main()
{
	unsigned int i=1,mask=1,n=-1;
	for(i = 32; i > 0; i--)
	{
		mask = 1;
		printf("%d ",((n&(mask<<i-1))?1:0));
	}
}

