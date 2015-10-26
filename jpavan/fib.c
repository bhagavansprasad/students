#include<stdio.h>
main()
{
 int i,p=-1,c=1,n;
 for(i=1;i<=8;i++)
 	{
	 n=p+c;
	 p=c;
	 c=n;

	 printf("%d",n);
	}
}
