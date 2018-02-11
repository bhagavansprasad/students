#include <stdio.h>

long int journey(int path_size, int *path, int k)
{
	long int sum = 0;
	int i, j, max = 0, newpos = 0;
	
	sum = path[0];
	for(i = 0 ; i < path_size;)
	{
		printf ("i :%3d, j :", i);
		j = i + 1;
		max = path[j];
		newpos = i+k;
		for(j = j+1; j <= (i+k) && j < path_size; j++)
		{
			printf ("  %3d,  ", j);
			if (path[j] > max)
			{
				max = path[j];
				newpos = j;
			}
		}
		sum += max;
		i = newpos;
		printf ("new :%3d, max :%5d, sum :%3d\n", newpos, max, sum);
		if (i == path_size-1)
			break;
		sleep(2);
	}
	return sum;
}

int main()
{
	//int array[] = {3, -4, -3, -5, 0};
	int array[] = {100, -70, -90, -80, 100};
	int path_size = sizeof(array)/sizeof(int);
	int i = 0;

	
	for(i = 0 ; i < path_size;i++)
	{
		printf ("%d  ", array[i]);
	}
	printf("\n");
	printf("Sum = %ld\n", journey(5, array, 2));
	return 0;
}

