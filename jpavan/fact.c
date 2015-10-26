#include<stdio.h>
main()
{
 int i,n=5,t,s=0;
   for(i=1;i<=n;i++)
    {
	 t=facti(i);
	 printf("%d\t",t);
	 
	}
}

int facti(int n)
 {
 int j,f=1;
    for(j=1;j<=n;j++)
	  {
	  f=f*j;
	  }
return f;
 }
