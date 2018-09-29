#include<stdio.h>
int main()
{
	int a,b,c,i,n=5;
	for(i=1;i<=5;++i)
	{
		a=getfact(i+1);
		b=getfact(i);
		c=a/b;
		printf("%d\n",c);
	}
}
int getfact(int n)
{
	int i,f=1;
	for(i=1;i<=n;i++)
		f=f*i;
	return f;
}
