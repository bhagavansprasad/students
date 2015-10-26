#include <stdio.h>
main()
{
int a[3][3]={{8,1,6},{3,5,7},{4,9,2}};
	int r,c,sum;
	for(r=0;r<3;r++)
	{
		for(c=0;c<3;c++)
		{
			sum=sum+a[r][c];
			printf("%d",a[r][c]);
			sum=0;
		}
		printf("\n");
	}
}
