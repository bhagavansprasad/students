#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_ELEMENTS 10

void insert_element(int *parray, int value, int index);
void delete_element(int *parray, int index);
void insert_order(int *parray, int value);
void del_dups(int *parray);
void del_dups_and_push(int *parray);

int main()
{        
	int i = 0;
	int array[NUM_OF_ELEMENTS] = {0}; 
	insert_element(array, 10, 0);
	insert_element(array, 20, 1);
	insert_element(array, 30, 2);
	insert_element(array, 40, 3);
	insert_element(array, 20, 4);
	insert_element(array, 60, 5);
	insert_element(array, 70, 6);
	insert_element(array, 30, 7);

	printf("--> After insertion of elements <--\n");
	
	for(i=0 ; i<NUM_OF_ELEMENTS ; i++)
		printf("array[%d] -> %d\n", i, array[i]);

	delete_element(array, 1);
	delete_element(array, 4);
	delete_element(array, 2);
	delete_element(array, 6);

	printf("--> After deletion of elements <--\n");

	for(i=0 ; i<NUM_OF_ELEMENTS ; i++)
		printf("array[%d] -> %d\n", i, array[i]);

	insert_order(array,30);
	insert_order(array,50);
	insert_order(array,60);
	insert_order(array,90);
	
	printf("--> After ordering of elements <--\n");

	for(i=0 ; i<NUM_OF_ELEMENTS ; i++)
		printf("array[%d] -> %d\n", i, array[i]);

	
	del_dups(array);
	
	printf("--> After removing duplicates <--\n");

	for(i=0 ; i<NUM_OF_ELEMENTS ; i++)
		printf("array[%d] -> %d\n", i, array[i]);

	del_dups_and_push(array);
	
	printf("--> After removing dups and pushing <--\n");

	for(i=0 ; i<NUM_OF_ELEMENTS ; i++)
		printf("array[%d] -> %d\n", i, array[i]);

	return 0;
}

void insert_element(int *parray, int value, int index)
{
	*(parray + index) = value;
}

void delete_element(int *parray, int index)
{
	int i=0;
	for(i=index ; i < NUM_OF_ELEMENTS-1 ;i++)
		*(parray + i) = *(parray + i + 1);
}

void insert_order(int *parray, int value)
{
	int i=0,j=0;
	for(i=0 ; i<NUM_OF_ELEMENTS ; i++)
	{
		if(i == NUM_OF_ELEMENTS-1 && *(parray+i) >= value)
		{
			*(parray+i) = value;
			return;
		}
		if(*(parray+i) < value)
		{
			if(*(parray+i) == 0)
			{
				*(parray+i) = value;
				return;
			}
			continue;
		}
		if(*(parray+i) == value)
		{
			*(parray+i) = value;
			return;
		}
		for(j=NUM_OF_ELEMENTS-1 ; j>i ; j--)
			*(parray+j) = *(parray+j-1);
		*(parray+i) = value;
		if(j == i)
			return;
	}
}

void del_dups(int *parray)
{
	int pass=0, i=0;
	for(pass=0 ; pass<NUM_OF_ELEMENTS ; pass++)
	{
		for(i=pass ; i<NUM_OF_ELEMENTS-1 ; i++)
		{
			if(*(parray+pass) == *(parray+i+1))
				*(parray+i+1) = 0;
		}
	}
}

void del_dups_and_push(int *parray)
{
	int pass=0, i=0, j=0;
	for(pass=0 ; pass<NUM_OF_ELEMENTS ; pass++)
	{
		for(i=pass ; i<NUM_OF_ELEMENTS-1 ; i++)
		{
			if(*(parray+pass) == *(parray+i+1))
			{
				for(j=i+1 ; j<NUM_OF_ELEMENTS-1 ; j++)
					*(parray+j) = *(parray+j+1);
			}
		}
	}
}
