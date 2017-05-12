#include<stdio.h>
void main()
{
	int n,r,rows=5,ncr=0,space;
	for(n=0;n<rows;n++)
	{
		for(space=0;space<=rows-n;space++);
		{
			printf(" ");
			for(r=0;r<=n;r++)
			{
				if(n==0||r==0)
				{
					ncr=1;
					printf("%7d",ncr);
				}
				else
				{
					ncr=ncr*(n-r+1)/r;
					printf("%3d",ncr);
				}
			}
		}
		printf("\n");
	}
}

