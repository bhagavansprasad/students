#include <stdio.h>
main()
{
	int i,num=0;
	printf("pattern\n");
	char bit;
	for(i=1;i<=32;i++)
	{
		bit=getchar();
		if(bit=='0')
		num=num<<1;
		else if(bit=='1')
		num=(num<<1)+1;
		else
		break;
	}
	printf("decimal value is %d\n",num);
}
