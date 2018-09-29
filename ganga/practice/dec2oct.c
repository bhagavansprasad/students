#include <stdio.h>
main()
{
	int i=0,b[6], a=65;
	while(a>7)
	{
		b[i]=a%8;
		a=a/8;
		i++;
	}
	b[i]=a;
	for(i;i>=0;i--)
	{
	printf("%d\n",b[i]);
	}
}
