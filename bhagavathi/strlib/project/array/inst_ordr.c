#include <stdio.h>

int arr[100];
int max = 100;
int noe = 0;

void dump_array()
{
	int i = 0;

	for(i=0; i < noe; i++)
		printf(" %3d", arr[i]);
	printf("\n");
}

int ordered_insert (int value)
{
	int i,j;

	if (noe == max)
	{
		printf("Array is full :%d\n", noe);
		return -1;
	}

	if(noe==0)
	{
		arr[0]=value;
		noe++;
		return 0;
	}
	for(i = 0; i < noe; i++)
	{
		if(arr[i] > value)
		{
			for(j = noe; j > i; j--)
				arr[j]=arr[j-1];
			arr[i]=value;
			noe++;
			return 0;
		}

	}
	arr[noe]=value;
	noe++;
	return 0;
}
main()
{
	int i;

	ordered_insert(0);
	ordered_insert(8);
	ordered_insert(6);
	ordered_insert(12);
	ordered_insert(15);
	ordered_insert(3);
	ordered_insert(7);
	ordered_insert(1);
	ordered_insert(1000);
	ordered_insert(3);
	ordered_insert(33);
	ordered_insert(24);
	ordered_insert(61);
	dump_array(); 
}

