#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int n, i, status=1;
	cout<<"Enter n number :";
	cin>>n;
	//status=1;
	for(i=2;i<=n/2;i++)
	{
		if(n%i==0)
		{	
			//status=0;
			cout<<n<<"it is not prime\n ";
		     exit(0);
		}
	}
        
		cout<<"it is a prime number\n";
}


