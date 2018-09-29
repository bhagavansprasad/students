#include <stdio.h>
#include <stdlib.h>

void display(int p[][5], int row, int col);
void display1(int *p, int row, int col);
void display2(int (*p)[5], int row, int col);

int main()
{
	int a[4][5] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15},
	{16,17,18,19,20}};
	printf("--> Display <--\n");
	display(a, 4, 5);
	printf("--> Display1 <--\n");
	display1(a, 4, 5);
	printf("--> Display2 <--\n");
	display2(a, 4, 5);
	return 0;
}

void display1(int *p, int row, int col)
{
	int i,j;
	for(i=0 ; i<row ; i++)
	{
		for(j=0 ; j<col ; j++)
			printf("a[%d][%d] : %d\t", i,j,*(p + i*col + j));
		printf("\n");
	}
}
void display2(int (*p)[5], int row, int col)
{
	int i,j,*t;
	for(i=0 ; i<row ; i++)
	{
		t =(int *) p + i;
		for(j=0 ; j<col ; j++)
			printf("a[%d][%d] : %d\t", i,j,*(t + j));
		printf("\n");
	}
}
void display(int p[][5], int row, int col)
{
	int i,j;
	for(i=0 ; i<row ; i++)
	{
		for(j=0 ; j<col ; j++)
			printf("a[%d][%d] : %d\t", i,j,p[i][j]);
		printf("\n");
	}
}
