
#include<iostream>
using namespace std;
int main()
{
	int y;

	cout<<"enter_year";
	cin>>y;
	if(y%4==0 && y!=0 or y%400==0)
	{
		cout << y << "is a leap year";
	}
	else
	{	
		cout<<y<<"not a leap year";

	}
	if(y==0)
	{
		cout<<y<<"is not an year";
	}	
}	
