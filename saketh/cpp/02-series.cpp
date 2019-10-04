#include<iostream>
using namespace std;
int main()
{
	int n=8,i,j,t=1;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=t;j++)
			cout<<j;
		cout<<endl;
		t=t+1;
	}
}   
