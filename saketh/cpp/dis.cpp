
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{	
	int m;
	{
		cout << "enter marks";
	}
	cin>>m;
	if(m<0)
	{	
		cout << "not valid\n";
			exit(0);
	}		
	if(m>=80)
	{
		cout << "dis\n";
	}
	if(m>=60)
	{
		cout << "first class\n";
	}
	if(m>=50)
	{
		cout << "second class\n";
	}
	if(m>=35)
	{
		cout << "just pass\n";
	}
	if(m<35)
	{
		cout << "fail\n";
	}  
}
