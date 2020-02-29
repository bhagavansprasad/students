#include<iostream>
using namespace std;

#define SIZE 7
int main()
{
	int b[SIZE][SIZE]={{0}}; 
	int i=1, n=SIZE, r=0, c=n/2, j, rsum, csum, d1sum, d2sum;
	rsum = csum = d1sum = d2sum = 0;
	for(i=1;i<=n*n;i++)
	{
		b[r][c]=i ;
		r--;
		c++;
		if(r<0&&c>n-1)
		{ 
			r=r+2 ;
			c=c-1;
		}
		if(r<0)
			r=n-1;

		if(c>n-1)
			c=0;

		if(b[r][c]!=0)
		{	 
			r=r+2;
			c=c-1;
		}
	}

	for(r=0; r<=n-1;r++)
	{
		for(c=0; c<=n-1 ;c++ )
		{	
			cout<< b[r][c]<<" ";
		}			
		cout << endl;
	}


	for(r=0; r<=n-1;r++)
	{
		for(c=0; c<=n-1 ;c++ )
		{	
			rsum=rsum + b[r][c];
		}			
		cout<<"row sum :"<<rsum<<endl;
		rsum=0;
	}

	for(c=0;c<=n-1;c++)
	{
		for(r=0;r<=n-1;r++)
		{
			csum = csum + b[r][c];
		}
		cout<<"coloumn no:"<<csum<<endl;	
		csum=0;
	}	

	for(r=0;r<=n-1;r++)
		d1sum=d1sum+b[r][r];
	cout << "d1 sum is :"<< d1sum << endl;

	for(r=0, c=n-1; r <= n-1; r++, c--)
		d2sum = d2sum + b[r][c];
	cout<<"diagonal 2 sum is :"<<d2sum << endl;
}
