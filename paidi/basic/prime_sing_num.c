#include <stdio.h>
main()
{
	int i,a=100,count=0;
	//for(i=2;i<=a-1;i++)
	for(i=2;i<=a;i++)
	{
		if(a%i == 0)
		{
			count++;
			break;
		}
	}
	if(count != 0)
		printf("not prim number\n");
	else
		printf("prim number\n");
}
