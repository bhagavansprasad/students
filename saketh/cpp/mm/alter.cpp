#include<iostream>
using namespace std;
int print_nth_empty_elements(int *p, int size, int n)
{
	int i = 0,temp=0;

	for (i = 0; i < size ; i++)
		printf("%3d", i);
	printf("\n");

	for (i = 0; i < size ; i++)
		printf("%3d", p[i]);
	printf("\n");

	cout << "1,";

	for(i=2;i<size;i++)
	{
		i=i+1;

		if(p[i] == 0)
			temp++;

		if(temp == n)
		{
			cout<<i<<",";
			temp=0;
		    if(size < i)
			  break;
		}	  
	}
	cout << endl;
	return 0;
}

int main()
{
	int a[13] = {1,0,2,0,3,0,4,0,5,0,6,0,7};
	int size = 13;
	int n = 2;
	print_nth_empty_elements(a, size, n);
}


