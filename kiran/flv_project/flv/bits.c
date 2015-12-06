#include <stdio.h>
int main()
{
	unsigned int mask = 1, n = 5, i = 0, c = 0;
	for(i = 8; i > 0; i--)
	{
		mask = 1;
		c = ((n&(mask<<(i-1)))?1:0);
		printf("%d ",c);
		if(i==3 && c == 1||i == 1&&c == 1)
		printf("the bit is on \n");
		else
		printf("off\n");
	}
}
