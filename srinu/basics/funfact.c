#include<stdio.h>
int main()
{
	int a=5,b=6,c=5,t=0;
	t=srinugetfact(a);
	printf("%d\n",t);
	t=srinugetfact(b);
	printf("%d\n",t);
	t=srinugetfact(c);
	printf("%d\n",t);
}
int srinugetfact(int n)
{
	int f=1;
	int i=0;
	for(i=1;i<=n;i++)
	{
		f=f*i;
	}
return f;
}
