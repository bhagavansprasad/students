#include<stdio.h>
main()
{
	int i, l, j= 2, k, m = 5, n = 2;
 for(l= 1;l< 5;l++)
 {
	for(i= 1;i<= n;i++)
	{
		printf("%d",i);
	}
	for(k= 1;k<= m;k++)
	{
		printf(" ");
	}
	for(  ;0< j && j<= 5;j--)
	{
		printf("%d",j);
	}
	n=n+1;m=m-2;j=n;
	printf("\n");
 }
}


