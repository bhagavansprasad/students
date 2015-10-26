#include<stdio.h>
main()
{
	int a=-1,b=1,n=5,i,s;
	for(i=0;i<=n;i++)
	{
		s=a+b;
		printf("%d\t",s);
			a=b;
		    b=s;
	}
}

