#include <stdio.h>
main()
{
	unsigned int a=0x15141312;
	int count=0,i,n=4;
	char *c;

	c = (char*)&a;
	for(i = (n-2); i >= 0; i--)
	{
		count++;
		printf("%x",*(c+i));
		if (count == 1)
		{
			i=i+2;
		}

		if(count == 2)
		{
			count=0;
			i-=2;
		}
	}
}
