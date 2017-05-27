#include <stdio.h>
int main()
{
	int n=3,r=0 , c=(n/2) , i ;
	int a[3][3];
	for(i=1 ; i<=n*n ; i++)
	{
		a[r][c]=i;
		r--;
		c++;



		if(i%n==0 )
		{
			r=r+2;
			c--;
		} 

		if(r<0)
		{
			r=n-1;
		}

		if(c>(n-1))
		{
			c=0;
		}
	}

	for( r = 0; r< n ; r++)
	{
		for( c = 0; c< n ; c++)
		{ 
			printf("%d\t", a[r][c]);
		}
		printf("\n");
	}
}

