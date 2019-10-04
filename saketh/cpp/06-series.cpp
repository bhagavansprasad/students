#include<iostream>
using namespace std;
int main()
{
	int n=5,i,j,x=n-1;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=x;j++)
			cout<<" ";
			
		for(j=1;j<=i;j++)
		{
			cout<<j;

		}
		cout<<endl;
		x--;

	}
}		  

