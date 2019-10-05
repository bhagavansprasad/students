#include<iostream>
using namespace std;
int main()
{
	int i=5, j=0, n=5, temp=n,x=0;
	int a[5]= {5,3,1,8,6};

	cout << "Before sorting array elements are..." << endl;
	for(i=0; i <= n-1; i++)
		cout << a[i] << " ";
	cout << endl;

	for(i = 0; i <= n-2; i++ )
	{
		for(j = 0; j <= temp-2; j++)
		{	

			if(a[j] < a[j+1])
			{
				x      = a[j];
				a[j]   = a[j+1];
				a[j+1] = x;
			}			
		}
		temp=temp-1;	
	}

	cout << "After sorting array elements are..." << endl;
	for(i=0; i <= n-1; i++)
		cout << a[i] << " ";
	cout << endl;
}
