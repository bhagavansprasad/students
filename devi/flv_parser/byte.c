#include <stdio.h>
#include <math.h>
#include <stdbool.h>
main()
{
	int i;
	char buff[100];
	int f;
	
	for(i=1;i<=3;i++)
	buff[i-1]=i*10;

	for(i=0;i<3;i++)
	printf("%d\n",buff[i]);
	
	for(i=0;i<3;i++)
	{
		f=(buff[i]&0xf0)>>4;
		printf("%d\n",f);
	}

}
