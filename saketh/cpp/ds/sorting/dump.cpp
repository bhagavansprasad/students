#include<iostream>
#include<cstdlib>
#include <iomanip>

using namespace std;
extern int data[10];

int dump_array(int n)
{
	int i=0;
	cout << "POS :";
	for(i=0; i <= n-1; i++)
		cout << setw(3) << i;

	cout << endl;

	cout << "VAl :";
	for(i=0; i <= n-1; i++)
		cout << setw(3) << data[i];

	cout << endl;
	cout << endl;
	return 0; 
}
