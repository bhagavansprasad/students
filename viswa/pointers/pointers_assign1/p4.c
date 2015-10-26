#include <stdio.h>
main()
{
	unsigned int a=0x15141312;
	int count=0,i,n=4;
	char *c;
	c=(char*)&a;
	for(i=0;i<=3;i++)
	{
		count++;
		if(count>2)
		{
			*(c+i)=0;
		}
		if(*(c+i)==0)
		{
			printf("0");
		}
		printf("%x",*(c+i));
	}
}
