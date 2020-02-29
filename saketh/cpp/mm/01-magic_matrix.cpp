#include<iostream>
using namespace std;

#define MATRIX_SIZE 3
int dump_matrix(int mtrx[][MATRIX_SIZE], int n)
{
	int i, r, c, j;
	cout << endl;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			cout << mtrx[i][j] << "  ";
		cout << endl;
	}
	cout << endl;

	return 0;
}

int populate_magic_square(int mtrx[][MATRIX_SIZE], int n)
{
	int i, r, c, j;

	r = 0;
	c = n/2;
	for(i = 1; i <= n*n; i++)
	{
		mtrx[r][c] = i;
		r--;
		c++;

		if(r < 0 && c > n-1)
		{ 
			r = r + 2;
			c = c - 1;
		}
		if ( r < 0)
			r = n - 1;

		if (c > n-1)
			c = 0;

		if( mtrx[r][c] != 0)
		{	 
			r = r + 2;
			c = c - 1;
		}
	}
	return 0;
}

int validate_magic_matrix(int mtrx[][MATRIX_SIZE], int n)
{
	int s = 0,s2,s3;
	int i, j;
	cout << endl;
	//rows_and_coloumns
	for(i = 0; i < n; i++)
	{
		s = 0;
		for(j = 0; j < n; j++)
			s = s + mtrx[i][j];
		cout << i << ":" << s << endl;
	}
	//diagnoal_1
	for(i = 0; i <= n-1; i++)
	{
		s2 = 0;			
		s2 = s2 + mtrx[i][i];
		cout << i << ":" << s2 << endl;
	}
	//diagnoal 2
	for(i = 0; i <= n-1; i++)
	{
		s3 = 0;
		for(j = n-1 ; j >=0; j--)
			s3 = s3 + mtrx[i][j];
		cout<<i<<":"<<s3<<endl;
	}		 
	return 0;
}

int main()
{
	int n = MATRIX_SIZE;
	int a_matrix[MATRIX_SIZE][MATRIX_SIZE]=  {{0}};

	cout << "Before populating...";
	dump_matrix(a_matrix, n);

	populate_magic_square(a_matrix, n);

	cout << "After populating...";
	dump_matrix(a_matrix, n);

	cout << "Validating magic matrix...";
	validate_magic_matrix(a_matrix, n);
}		
