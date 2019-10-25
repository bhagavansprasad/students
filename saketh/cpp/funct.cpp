#include<iostream>
using namespace std;
void is_prime(int n)
{
	int i;
	for(i=2;i<=n-1;i++)
	{ 
		if(n%i==0)
			break;
	}	
	if(n==i)
		cout<<n<<"  is prime"<<endl;
	else
		cout<<n<<"  is not prime"<<endl;
}
int main()
{
	int a=5,b=9,c=16;
	is_prime(a);
	is_prime(b);
	is_prime(c);

}	
