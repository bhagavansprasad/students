#include <stdio.h>
static char i=1;
main()
{
	int j;
	for(j=0;j<255;j++)
	{
		printf("%d\n",i);
		i++;
	}
}
