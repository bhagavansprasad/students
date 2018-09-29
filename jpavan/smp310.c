#include<stdio.h>
main()
{
int i,j,n=5;
for(i=1;i<=n;i++)
	{
	 for(j=1;j<=n-i+1;j++)
	  {
        printf("%3d",j);
	  }
	  printf("\n");
	 }
}
