#include <stdio.h>
main()
{
	int n=5,i,f=1;
	for(n=1;n<=5;n++)
	{
	for(i=n;i>=1;i--)
	{
		f=f*i;
		break;
	}
	printf("%d\t",f);
	}
}
