#include<iostream>
#include<cstdlib>
using namespace std;
//using boost::format;

int A[100] = {1,2,3,4,5};
int noe=5;
int dump_array(int *p, int n)// it is there just to show positions
{
	int i = 0;
	cout << "Position#";
	for (i = 0; i <= n; i++)
	 	cout << i<<",";
	cout << endl; 
	cout << "elements#";
	for (i = 0; i < n; i++)
		cout << p[i] << ",";
	cout << endl;
	cout << endl;
	return 0;
}

int insertion_value_by_postion(int *pA, int val, int pos )
{
	int i=0;
	cout << "Inserting " << val << " at " << pos << endl << endl;
	if(noe == 0)
	{
	 	cout << "NOTHING TO INSERT THE VALUE TO "<<endl;
		return 0;
	}
	if(pos > noe)
 	{
	 	cout << "Invalid position :" << pos << endl;
		return 0;
	}	 
	for(i = noe-1; i >= pos; i--)
		pA[i+1] = pA[i];
	pA[pos]=val;
	noe++; 
	return 0;
}

int main()
{ 
	int value=9, pos=2;
	dump_array(A, noe);

    insertion_value_by_postion(A,  value, pos);
	dump_array(A, noe);

    insertion_value_by_postion(A, 10, 3);
	dump_array(A, noe);
    insertion_value_by_postion(A, 17, 0);
	dump_array(A, noe);
}	
