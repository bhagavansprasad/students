
#include<iostream>
using namespace std;
int main()
{
	int y;

	cout<<"enter_year";
	cin>>y;
	if(y%4==0 && y!=0 or y%400==0)
	{
	   cout<<"leap year";
	}
	else
	{	
		cout<<"nt_a_leap_year";

	}
	if(y==0)
	{
		cout<<"not an year";
	}	
}	
