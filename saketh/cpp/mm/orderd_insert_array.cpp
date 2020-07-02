#include<iostream>
#include<cstdlib>
using namespace std;

int A[10] = {};
int noe=0;
int max_size = 10;

int insertion_value_by_postion(int val, int pos)
{
	int i=0;
	//cout<<" noe:"<<noe<<endl;
	if(noe == max_size)
	{
		cout << "overflow : "<<endl;
		return 0;
	}

	if(pos > noe)
	{
		A[pos]=val;
		return 0;
	}	 

	for(i = noe-1; i >= pos; i--)
	{
		A[i+1] = A[i];
	}

	A[pos]=val;
	noe++; 

	return 0;
}

int orderd_insert(int val)
{
	int i=0;
	//cout << "In Ordered insert val :" << val << endl;
	//cout << "In Ordered insert noe :" << noe << endl;
	//
	for(i = 0; i <= noe-1; i++)
	{
		if(A[i] >= val)
		{
			insertion_value_by_postion(val, i);
			return 0;
		}	
		if (A[i] <= val && A[i+1] >= val)
		{
			insertion_value_by_postion(val, i+1);
			return 0;
		}

	}
	insertion_value_by_postion(val , noe);
    return 0;      
}

int dump_array(void)
{
	int i = 0;

	cout << "Position#";
	for (i = 1; i <= noe; i++)
		cout << i<<",";

	cout << endl; 
	cout << "elements#";

	for (i = 0; i < noe; i++)
		cout << A[i] << ",";

	cout << endl;
	cout << endl;

	return 0;
}

int main()
{
	int test_data[50]={ 0, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4};
	int i;
	dump_array();

	for(i = 0; i <= 11-1; i++)
		orderd_insert(test_data[i]);

	dump_array();
}

