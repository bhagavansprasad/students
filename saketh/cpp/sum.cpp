#include<iostream>
using namespace std;
int main()
{	
	int sum=0, a=123;
	while(a!=0)
	{
		sum= a%10+sum;
		a=a/10;
	}
	cout <<sum<<" is The sum of digits"<<endl;

}	



