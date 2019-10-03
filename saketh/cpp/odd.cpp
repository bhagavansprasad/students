#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{	
	int a;
	cout << "enter number :";
	cin >> a;
	if(a<=0)
	{
		cout << a << " is invalid input " << "\n";
		exit(0);
	}
	if(a%2==1)
	{	
		cout << a << " is Odd" << "\n";
	}	
	else
	{	
		cout << a << " is Even" << "\n";
	}
}	
