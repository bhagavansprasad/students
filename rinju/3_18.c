#include<stdio.h>
main()
{
	int i,j,a=65,n=5,temp;
	for(i=1;i<=n;i++)
	{
			temp=a;
		for(j=1;j<n;j++)
		{
			if(j<=n/2)

			{
			printf("%c",temp);
				++temp;
			}
			else
				temp--;
			printf("%c",temp);
		}
		printf("\n");
	}
}
