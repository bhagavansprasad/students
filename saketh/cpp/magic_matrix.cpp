#include<iostream>
using namespace std;
int main()
{
	int a[5][5]= 
	{
		{0,0,0},
		{0,0,0},
		{0,0,0}
	};
	int i=1,n=5, r=0,c=n/2,j;

	for(i=1;i<=n*n;i++)
	{
		a[r][c] = i;
		r--;
		c++;

		if(r < 0 && c > n-1)
		{ 
			r = r + 2 ;
			c = c - 1;
		}
		if(r < 0)
			r = n-1;

		if(c > n-1)
			c = 0;

		if(a[r][c] != 0)
		{	 
			r = r + 2;
			c = c - 1;
		}
	}	
	cout<<  i  << r << "  " << c << endl;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			cout<< a[i][j] << " ";
		cout << endl;
	}
}		
