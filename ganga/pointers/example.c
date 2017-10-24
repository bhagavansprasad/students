#include <stdio.h>

main()
{
	int a[3][4] = { 1, 2, 3, 4,
		5, 6, 7, 8,
		9, 0, 1, 6,
	};
	display(a, 3, 4);
}
void display(int *q, int row, int col)
{
	int i, j;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			printf("%d  ", *(q + i * col +j));
		}
		printf("\n");
	}
	printf("%d %d\n", sizeof(q), sizeof(*q[4]));
}

