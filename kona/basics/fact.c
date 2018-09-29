#include<stdio.h>
main()
{
	int n=5,t=0;
	t=fact(n);
	printf("%d",t);
}
int fact(int n)
{

	int c,f=1;
	for(c=1;c<=n;c++)
{
	f=f*c;
}
return (f);
}

