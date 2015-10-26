#include <stdio.h>
char c;
main()
{
	signed int i=1,n=0;
	//char c;
	while(i<=65535)
	{
	printf("i=%d\n", i);
	i++;
	}
	//printf("i=%d\n", i);
	while(n<=255)
	{
	printf("c = %d\n", c);
	c++;
	n++;
	}
	//printf("c = %d\n", c);
}
