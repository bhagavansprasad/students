# include <stdio.h>
main ()
{
	int a[5] = { 5,2,6,4,8 };
	int i,j,temp,n = 5;
	for (i = 0;i < n ;i++)
	{
		for (j = i+1;j < n;j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("sorted list");
	for (i = 0;i < n;i++)
	{
		printf("%d\t",a[i]);
		printf("\n");
	}
}
