#include "amath.h"
#include "stdio.h"
int amath::isprime(int n)
{
	int i;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		{
		  cout<<"is NOT prime"<<endl;
          return 1;
		}
	}
	cout << n << ": is prime" << endl;
	return 0;
}	
