#include<stdio.h>
main()
{
	int x=2,y=1,k,sum=0,i,n=5;
	for(i=0;i<n;i++)
	{
		k=fact(x+i)/fact(y+i);
		sum=sum+k;
	}
	printf("%d",sum);
	return 0;
}
	int fact(int x)
	{
		int i,f=1;
		for(i=1;i<=x;i++)
		f=f*i;
	return(f);
	}
