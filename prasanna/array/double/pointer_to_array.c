#include<stdio.h>
#include<malloc.h>
int fun(int (*p)[3],int n)
{
	int *q = (int*)malloc(sizeof(int )*n);
	int i,j;
	for(i=0;i<n;i++)
	{
		q = p++;
		for(j=0;j<3;j++)
		{
			printf("%d\n",*(q+j));
		}
	}
}	
int main()
{
	int array[4][3]={1,2,3,
			 4,5,6,
			 7,8,9,
			 10,11,12};



	fun(array,4);
}
