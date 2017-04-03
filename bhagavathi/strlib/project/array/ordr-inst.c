#include <stdio.h>
int ordr_inst(int *a,int n,int pos,int k);
main()
{
	int arr[];//={4,67,9,3,8,3,81,21,71};
	int pos=6,arrsize,i,num=9;
	printf("enter the elements");
	scanf("%d",&arr);
	arrsize  = sizeof(arr)/sizeof(int);

	printf("before \nnum: %d pos: %d",num,pos);
	printf("\n");
	for( i = 0; i < arrsize ; i++)
		printf("%3d", arr[i]);
	printf("\n");

	
	x=ordr_inst(arr,num,pos,arrsize);
	
	printf("\n");
	printf("after \nnum: %d pos: %d",num,pos);
	printf("\n");
	for ( i = 0; i < arrsize+1; i++)
		printf("%3d",arr[i]);
	
	printf("\n");
}
int ordr_inst(int *a,int n,int pos,int k)
{
	int q,i,j,temp=0;
	for(i=0; i<k; i++ )
	{	
		if(i==pos)
		{
			for(q=k; q>pos; q--)
			{
				a[q+1]=a[q];
				a[pos]=n;
			}
		}
		for(j=i+1; j<k; j++)
		{
			if( a[i] > a[j] )
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	return a[i];
}
