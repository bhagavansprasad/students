#include<stdio.h>
main()
{
 int i,p=-1,c=1,n,s;
 for(i=1;i<=8;i++)
 	{
	 n=p+c;
	 p=c;
	 c=n;
	 printf("%d\n\t",n);
	 s=s+n;
	 printf("%d\n",s);
	}
}
