# include <stdio.h>
main ()
{
	int a[5] = { 5,2,6,4,8 };
	int i,j,x,temp,n = 5;
	for (i = 0;i < n-1 ;i++)
	{
		x = 0;
		for (j = 0;j < n-1-i ;j++)
		{
			if ( a[j] > a[ j+1 ])
			{
				temp = a[j];
				a[j] = a[ j+1 ];
				a[ j+1 ] = temp;
				x++;
			}
		}
	if (x == 0)
	break;
	}
	printf("sorted list");
	for (i = 0;i < n; i++)
		printf("%2d",a[i]);
		printf("\n");
}

