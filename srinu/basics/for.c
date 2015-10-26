#include<stdio.h>
int main()
{
	int x,y,z,i,n=5;
	x=0,y=1;
	for(i=0;i<n;i++)
	{
		z=x+y;
		x=y;
		y=z;
		printf("%d\n",z);
	}
	printf("\n");
}
