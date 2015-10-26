#include <stdio.h>
main()
{
	int a[10]={12,4,54,6,8,5,12,47,25,59};
	int i=0,j,big,secondbig,n=10;
	big=a[0];
	for(i=0;i<n;i++)
	{
		if(big<a[i])
		{
			big=a[i];
			j=i;
		}
	}
	secondbig=a[n-j-1];
	for(i=0;i<n;i++)
	{
		if(secondbig<a[i] && j!=i)
		secondbig=a[i];
	}
	printf("the secondbig is %d\n",secondbig);
}
