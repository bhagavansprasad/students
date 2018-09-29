#include <stdio.h>
main ()
{
int i,j,num;
int n = 5;
int c[20][20];
i = n-n;
j = (n-1)/2;
for (num = 1; num <= n*n ; num++)
{
	c[i][j] = num;
	i--;
	j++;
	if (num%n==0)
	{
		i += 2;
		j--;
	}
	else if (i == -1)
			i = n-1;
	else if (j == n)
			j = 0;
}
for (i = 0;i < n;i++)
{
	for (j = 0;j < n;j++)
	{
		printf("%5d",c[i][j]);
	}
	printf("\n");
}
}
