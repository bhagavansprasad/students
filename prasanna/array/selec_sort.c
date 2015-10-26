/* Selection Sort */

#include<stdio.h>
int main()
{
	int array[20];
	int i,j,n,temp;
	printf("Enter the size of an array\n");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&array[i]);
	printf("The input array is\n");
	for(i=0;i<n;i++)
		printf("%d\n",array[i]);
	
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(array[i] >= array[j])
			{
				temp = array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
	}
	
	printf("The sorted array is\n");
	for(i=0;i<n;i++)
		printf("%d\n",array[i]);
	return 0;
}

/*
#include<stdio.h>

int main()
{
 int a[10],i,j,k,t;
 printf("Please enter 10 values:\n");
 for(i=0;i<5;i++)
  scanf("%d",&a[i]);
 
 for(i=0;i<5;i++)
 {
  k=i;
  for(j=i;j<5;j++)
  {
   if(a[k]>a[j])
    k=j;
  }
  if(k!=i)
  {
   t=a[k];
   a[k]=a[i];
   a[i]=t;
  }
 }
 
 printf("Sorted Array is:\n");
 for(i=0;i<5;i++)
  printf("%d\n",a[i]);
 
 return 0;
}
*/
