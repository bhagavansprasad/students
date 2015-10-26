#include<stdio.h>
#include<math.h>

main()
{
	int i,a=0;
	for(i=2;i<6;i++)
	{
		a=a+pow(2,(i-2));
	}
	printf("%d\n",a);
}
