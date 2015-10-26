/*Pascal Triangle 
  1
  1 1
  1 2 1
  1 3 3 1 
  1 4 6 4 1
 */
#include<stdio.h>

long fact(int);

int main()
{
	int i, j,n;
	printf("Enter the n value\n");
	scanf("%d",&n);

	
	
	for (i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("%6ld ",fact(i)/(fact(j)*fact(i-j)));
		}
		printf("\n");
		
	}
		
	
	return 0;
}

long fact(int n)
{
	int i;
	long f = 1;
	for(i=1;i<=n;i++)
		f = f*i;
	return f;
}
