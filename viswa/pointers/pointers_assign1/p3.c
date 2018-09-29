#include <stdio.h>
main()
{
	unsigned int a=0x15141312;
	int count=0,i,n=4;
	char *c;
	c=(char*)&a;
	for(i=1;i>=0;i--)
	{
		count++;
		printf("%x",*(c+i));
		if(count==2)
		{
			i+=4;
		}
		if (count==4)
		{
			break;
		}
	}
}
