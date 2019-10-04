#include<iostream>
using namespace std;
int main()
{
	int n=5,i,j;
	int t = n;

	for(i=1; i <= n;i++)
	{
		for(j = 1; j <= t; j++)
			cout<<j;
		t--;
		cout<<endl;
	}
}   
