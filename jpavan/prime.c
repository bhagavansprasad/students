#include<stdio.h>
main()
{
int i,n=4,p,flag;
   for(i=2;i<=n-1;i++)
    {
	 p=(n%i);
	 if(p==0)
	 {
	 flag=1;
	 break;
	 }
	}
	if(flag==1)
	printf("not prime\n");
	else
	printf(" prime\n");
}
