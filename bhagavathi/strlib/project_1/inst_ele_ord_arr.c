#include <stdio.h>

int arr[100];
int max_arr_size = 100;
int noe = 0;

void dump_array()
{
	int i = 0;

	for(i=0; i < noe; i++)
		printf("%3d", arr[i]);
	
	printf("\n");
}

int ordered_insert (int value)
{
	int i,j;

	if (noe == 0)
	{
		arr[0] = value;
		noe++;
		return 0;
	}

	for(i=0; i < noe; i++)
	{
		if(i==pos)
		{
			for(j=noe ; j >= pos; j--)
			{
				a[j+1]=a[j];
			}
			a[pos]=value;
		}
	}
}

main()
{
	int i;

	dump_array();

	ordered_insert(10);

	dump_array();
}
