#include<iostream>
#include<cstdlib>
using namespace std;

int A[100] = {5, 7, 2, 5, 9, 1};
int noe = 6;

int dump_array(int *p, int noe)
{
	int i = 0;
	cout << "Possion  #";
	for (i = 1; i <= noe; i++)
		cout << i << "  ";

	cout << endl; 

	cout << "elements #";
	for (i = 0; i < noe; i++)
		cout << p[i] << "  ";

	cout << endl;
	cout << endl;
	return 0;
}

int deletion_by_position(int *pA, int pos)
{
	int i;

	cout << "Deleting " << pos << " Element..." << endl << endl;
	if(noe == 0)
	{
	 	cout << "No elements to delete :" << pos << endl;
		return 0;
	}

	if(pos > noe)
 	{
	 	cout << "Invalid position :" << pos << endl;
		return 0;
	}	 

	i = pos;
	for(i = pos-1; i <= noe; i++)
		pA[i] = pA[i+1];
	noe--;

	return 0;
}

int main()
{
	int position = 6;

	dump_array(A, noe);
	deletion_by_position(A, position);
	dump_array(A, noe);

	deletion_by_position(A, 1);
	dump_array(A, noe);

	deletion_by_position(A, 3);
	dump_array(A, noe);

	deletion_by_position(A, 6);
	dump_array(A, noe);

	deletion_by_position(A, 2);
	dump_array(A, noe);

	deletion_by_position(A, 1);
	dump_array(A, noe);

	deletion_by_position(A, 2);
	dump_array(A, noe);

	deletion_by_position(A, 1);
	dump_array(A, noe);

	deletion_by_position(A, 0);
	dump_array(A, noe);
}	

