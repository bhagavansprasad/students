#include <stdio.h>
#define MAX 100
main()
{
	int a[MAX]={0};
	int p,i,n;
	printf("enter the n:");
	p=2;
	while(p*p<=n)
	{
		for(i=2;i*p<=n;i++)
		a[i*p]=1;
		for(i=p+1;i<=n;i++)
		if(a[i]==0)
		{
			p=i;
			break;
		}
	}
	for(i=2;i<=n;i++)
	if(a[i]==0)
	printf("%d",i);
	return 0;
}
