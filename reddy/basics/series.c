#include <stdio.h>
main()
{
int i,n=5,f=1,x=1,sum,fact;
for(i=1;i<=n;i++)
{
	sum=sum+fact(x+i)/fact(i);
}
printf("%d",sum);
return 0;
}
int fact(int x)
{
for(i=1;i<=x;i++)
	{
	f=f*i;
	}
return(f);
}
