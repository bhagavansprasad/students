#include<iostream>
using namespace std;
int print_nth_empty_element(int *p, int size, int n)
{
	int i = 0, c = 0, j = 1;

	for(i=0; i <= 12; i++)
		p[i] = 0;
	
	for(i=0; i <= 12; i++)
		cout << " " << p[i];
	cout << "\n";

	for(i=0;;i++)
	{
		cout << "i :" << i << endl;
		if(p[i]==0)
			c++;
		if(c == n)
		{
			p[i]=j;
			j++;
			c=0;
		}
		if(i == size-1)
			i = -1;
       
		if(j == 13)
			break;
	} 	
	for(i=0;i<=size-1;i++)
		cout << " " << p[i];
	cout << "\n";
	
	return 0;
}
int main()
{
	int a[13], n=2;
	int s = 13 ;
	print_nth_empty_element(a, s, n);
}


