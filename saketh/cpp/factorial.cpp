#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{	
	int n, i=1, p=1;
	cout<<"Enter n value :";
	cin>>n;
	if(n<0)
	{	
		cout << "invalid input:"<<"\n";
		exit(0);
	}	
	while(i<=n)
	{
		p=p*i;
		i=i+1;
	}
	cout << "The factorial is:" << p <<"\n";
}







