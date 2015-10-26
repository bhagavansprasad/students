#include <stdio.h>
int check(int n )
{
	int i;

	for(i = 2;i<n;i++)
	{
		if(n%i==0)
			return 0;
	}
	if(n==i)
		return 1;
}
int prev(int n)
{
	int num,rval =-1;
	for(num = n-1;num > 1 ; num--)
	{
		rval = check(num);
		if(rval == 1)
			return num;
	}
}
int next(int n)
{
	int num,rval = -1;
	for(num = n+1; ; num++)
	{
		rval = check(num);
		if(rval == 1)
			return num;
	}
}
main()
{
	int num=3,n,p;
	//printf("enter a num :\n");
	//scanf("%d",&num);
	n=next(num);
	printf("next prime is : %d\n",n);
	p=prev(num);
	printf("prev prime is : %d\n",p);
}
