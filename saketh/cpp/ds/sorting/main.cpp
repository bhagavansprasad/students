#include<iostream>
#include<cstdlib>

using namespace std;

int n = 8;
int data[10]={1, 9, 4, 3, 7, 0, -5, 0};

int dump_array(int n);
int bubble_sort(int n);

int main()
{
	cout<<"Before sorting :" << endl;
	dump_array(n);

	bubble_sort(n);

	cout<<"After arrangement"<<endl;

	dump_array(n);
}




