/*
*Program: merge_array.c
*Purpose: merge two arrays of ints
*Inputs: 
*	asize, bsize: number of elements in input arrays
*	A, B: the two arrays to be merged
*Output:
*	C: the merged array
*Notes:
*	1. Maximum array size is set in MAX macro
*	2. There`s no check on input array sizes
*/

#include<stdio.h>
#define MAX 100
void readArray(int A[], int n);
void printArray(int A[], int n);
void merge(int A[], int asize, int B[], int bsize, int C[], int csize);
/******************************************
*Function: main
*/
int main()
{	
	int A[MAX], B[MAX], C[MAX];
	int asize, bsize, csize;
	
	printf("How many elements in A? B?\n");
	scanf("%d %d",&asize, &bsize);
	
	printf("Enter the elements of A in sorted order.\n");
	readArray(A, asize);
	
	printf("Enter the elements of B in sorted order.\n");
	readArray(B, bsize);
	
	csize = asize + bsize;
	merge(A, asize, B, bsize, C, csize);
	
	printf(" C = \n");
	printArray(C, csize); 
	
	return 0;
}/* main */
 
	 
/**********************************************
*Function: readArray
*Purpose: read in the contents os the array A
*Input arg: n,the number of the elements to be read
*Output arg: A, the array
*/

void readArray(int A[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	scanf("%d", &A[i]);
}/* readArray */

/**********************************************
*Function: printArray
*Purpose: print the contents of the array A
*Input args: 
*	n, the number of elements to be read
*	A, the array
*/

void printArray(int A[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}/* printArray */

/***************************************************
*Function: merge
*Purpose: merge the contents of the arrays A ana B into array C
*Input args: 
*	asize: the number of elements in A
*	bsize: the number of elements in B
*	csize: the number of elements in C
*	A, B: the arrays
*Output arg:
*	c: result array
*/
void merge(int A[], int asize, int B[], int bsize, int C[], int csize)
{
	int ai = 0, bi = 0, ci = 0, i;
	
	while((ai < asize) && (bi < bsize))
	{
		if (A[ai] <= B[bi])
		{
			C[ci] = A[ai];
			ci++;
			ai++;
		}
		else
		{
			C[ci] = B[bi];
			ci++;
			bi++;
		}
	}
	if(ai >= asize)
		for(i = ci; i < csize; i++, bi++)
			C[i] = B[bi];
	else
		for(i = ci; i < csize; i++, ai++)
			C[i] = A[ai];
}/* merge */

