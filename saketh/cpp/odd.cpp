#include<iostream>
using namespace std;
int main()
{	
	int a;
	cout << "enter number :";
	cin >> a;

	if(a%2==1)
	{	
		cout << "odd" << "\n";
		cout << a << " is Odd" << "\n";
	}	
	else
	{	
		cout << a << " is Even" << "\n";
	}
}	
