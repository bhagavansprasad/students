#include<iostream>
#include<cstdlib>
using namespace std;

#define M 6
#define N 6

int populate_array(int pa[][M], int row, int col)
{
	int k = 1, r, c;
    for(r=0; r <= row-1 ; r++)
		for(c=0; c<=col-1; c++, k++)
			 //a[r][c]=rand()%(m*n);
			 pa[r][c]=k;
	return 0;
}

int dump_array(int pa[][M], int row, int col)
{
	int r, c;
    for(r=0; r <= row-1; r++)
	{
		for(c=0; c<=col-1; c++)
			printf("%4d", pa[r][c]);
		printf("\n");
	}
	return 0;
}

int strip_matrix_new(int pa[][M],int sr,int sc, int row, int col)
{
	int r, c;
	cout<<endl;
	//printf("sr :%d, sc :%d, row :%d, col :%d\n", sr, sc, row, col);

	//printf("R1 -->");
	for(r=sr, c=sc ; c <= col-2; c++)
    	printf("%4d", pa[r][c]);
	//cout << endl;

	//printf("R2 -->");
	for(r = sr, c = col - 1; r <= row-2; r++)
    	printf("%4d", pa[r][c]);
	//cout<<endl;

	//printf("R3 -->");
	for(r = row-1, c = col - 1; c > sc; c--)
    	printf("%4d", pa[r][c]);

	//cout<<endl;

	//printf("R4 -->");
	for(c=sc,r=col-1; r>sr ; r--)
    	printf("%4d", pa[r][c]);

	cout<<endl;
    return 0;
}
int main()
{
	int a[M][N], k = 1;
	int i,n=N,temp=0, r,c,m=M,sr,sc;

	populate_array(a, m, n);
	dump_array(a, m, n);
	//strip_matrix(a, m, n);
    for(sr=0,sc=0,m=M,n=N;sr<=2;sr++,sc++,m--,n--)
	{
		strip_matrix_new(a, sr, sc, m, n);
	//`	return 0;
	}
                            // 0  0   6  6
                            // 1  1   5  5
                            // 2  2   4  4
}		
