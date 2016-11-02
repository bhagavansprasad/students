#include<stdio.h>
void main()
{
         int i,fact=1,n;
		 printf(" enter a num");
		 scanf("%d",&n);
		 if(n>=0)
		 {
		            for(i=1;i<=n;i++)
					{
					     fact=fact*i;
					}
		}
		printf("factorial %d",fact);
}
