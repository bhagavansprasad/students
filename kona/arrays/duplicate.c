#include<stdio.h>
int main()
{
	int arr[50]={1,2,3,4,5,6,7,8,9,10};
	int *p;
	int i,j,k,size,n=10;
	size=n;
	p=arr;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if(i==j)
			{
				continue;
			}
			else if(*(p+i)==*(p+j))
			{
				k=j;
				size--;
				while(k < size)
				{
					*(p+k)=*(p+k+1);
					k++;
				}
				j=0;
			}
		}
	}
	printf("\nThe array after removing duplicates is: \n");
	for(i=0;i < size;i++)
	{
		printf(" %d\n",arr[i]);
	}
	return 0;
}
