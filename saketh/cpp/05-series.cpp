#include<iostream>
using namespace std;
int main()
{
	int n=5,i,j;
	int t = 1;

	for(i=1; i <= n; i++)
	{
		for (j = n; j >= t; j--)
			cout << j;
		t = t + 1;
		cout << endl;
	}
}   
