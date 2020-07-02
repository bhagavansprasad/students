#include "amath.h"
int amath::factorial(int n)
{
	int f = 1;
	int i = 0;
	for(i = n; i >= 1; i--)
		f = f * i;
    cout<<"factorial is "<<f<<endl;
	return f;
}		

