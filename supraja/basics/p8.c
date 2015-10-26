#include  <stdio.h>
int main()
{
	int i,j,k,o,m,n=1;
	for(i=1;i<=5;i++,n++)
	{
	for(j=1;j<=i;j++)
	{
		printf("%d",j);
	}
	for(k=4;k>=i;k--)
	{
		printf(" ");
	}
	for(o=4;o>=i;o--)
	{
		printf(" ");
	}
	for(m=1;m<=n;m++)
	{
		printf("%d",m);
	}
	printf("\n");
}
}
